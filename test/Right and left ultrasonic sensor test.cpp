#include <Wire.h>
#include <ESP32Servo.h> 
#include <MPU6050_light.h> 

// ------------------------------------------------------------------------
// 1. Pin Definitions
// ------------------------------------------------------------------------
// Right Sensor Pins
#define TRIG_RIGHT 33
#define ECHO_RIGHT 35

// Left Sensor Pins
#define TRIG_LEFT  32
#define ECHO_LEFT  34

// Motor Pins
#define IN1 25    
#define IN2 26    
#define ENA 27    // PWM Speed Control Pin

// Servo & IMU Pins
#define SERVO_PIN 18 
#define SDA_IMU 4  
#define SCL_IMU 5

// ------------------------------------------------------------------------
// 2. Settings & Parameters
// ------------------------------------------------------------------------
const int MOTOR_SPEED = 190;          // Straight motor speed
const int TURN_SPEED = 190;           // Turning motor speed

// Servo Angles
const int SERVO_STRAIGHT = 70;        // Straight angle
const int SERVO_RIGHT = 25;           // Max right
const int SERVO_LEFT = 115;           // Max left

const float OPENING_THRESHOLD_CM = 50.0; // Opening detection threshold (> 50 cm)

// PID Parameters for Straight Drive
float Kp = 1.8;   
float Ki = 0.04;  
float Kd = 0.35;  

// ------------------------------------------------------------------------
// 3. Objects & Variables
// ------------------------------------------------------------------------
Servo myServo;
TwoWire I2C_IMU = TwoWire(1);          
MPU6050 mpu(I2C_IMU);                  

float targetAngle = 0.0;               
float errorSum = 0.0;                  
float lastError = 0.0;                 
unsigned long lastTime = 0;            

// Robot States
enum RobotState {
  MOVING_STRAIGHT,
  TURNING,
  STOPPED
};
RobotState currentState = MOVING_STRAIGHT;

// ========================================================================
// Function to measure distance in centimeters
// ========================================================================
float readDistanceCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 30ms timeout (approx. 5 meters)
  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999.0; // No echo implies wide open space (> 50 cm)
  }

  return (duration * 0.0343) / 2.0; 
}

// ========================================================================
// Function to compute PID and maintain straight heading
// ========================================================================
void computePID() {
  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0; 
  if (dt <= 0.0) dt = 0.01;

  float currentAngle = mpu.getAngleZ();
  float error = currentAngle - targetAngle; 

  errorSum += error * dt;
  errorSum = constrain(errorSum, -20.0, 20.0);

  float errorDeriv = (error - lastError) / dt;
  float pidOutput = (Kp * error) + (Ki * errorSum) + (Kd * errorDeriv);

  int servoAngle = SERVO_STRAIGHT - pidOutput;
  // Constrain servo movement during adjustments
  servoAngle = constrain(servoAngle, SERVO_RIGHT, SERVO_LEFT);

  myServo.write(servoAngle);

  lastError = error;
  lastTime = currentTime;
}

// ========================================================================
// Stop the robot completely
// ========================================================================
void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  ledcWrite(ENA, 0);
  myServo.write(SERVO_STRAIGHT);
  Serial.println("🛑 Robot stopped successfully.");
}

// ========================================================================
// Setup
// ========================================================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n🚀 Starting robot system...");

  // 1. Setup Ultrasonic Pins
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);

  // 2. Setup Servo
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myServo.setPeriodHertz(50); 
  myServo.attach(SERVO_PIN); 
  myServo.write(SERVO_STRAIGHT);

  // 3. Setup Motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  ledcAttach(ENA, 5000, 8); 

  // 4. Initialize I2C and Calibrate IMU
  I2C_IMU.begin(SDA_IMU, SCL_IMU);
  byte status = mpu.begin();
  if (status != 0) {
    Serial.println("❌ Failed to connect to IMU sensor!");
    while (1) delay(100);
  }

  Serial.println("⏳ Calibrating IMU, please do not move the robot...");
  delay(1500);
  mpu.calcOffsets();
  Serial.println("✅ IMU calibration complete.");

  // Save current angle as heading target
  mpu.update();
  targetAngle = mpu.getAngleZ();
  lastTime = millis();

  // Start Motor Drive
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  ledcWrite(ENA, MOTOR_SPEED);
  currentState = MOVING_STRAIGHT;
}

// ========================================================================
// Main Loop
// ========================================================================
void loop() {
  mpu.update();

  // --------------------------------------------------
  // State 1: Moving straight and detecting openings
  // --------------------------------------------------
  if (currentState == MOVING_STRAIGHT) {
    computePID();

    float distRight = readDistanceCM(TRIG_RIGHT, ECHO_RIGHT);
    delay(10); // Brief delay to prevent acoustic crosstalk
    float distLeft  = readDistanceCM(TRIG_LEFT, ECHO_LEFT);

    // Check for right opening
    if (distRight > OPENING_THRESHOLD_CM) {
      Serial.println("🚨 Right opening detected! Initiating turn...");
      targetAngle = mpu.getAngleZ() - 90.0; // Adjust target angle 90 degrees right
      myServo.write(SERVO_RIGHT);           // Steer wheels right
      ledcWrite(ENA, TURN_SPEED);           
      currentState = TURNING;
    }
    // Check for left opening
    else if (distLeft > OPENING_THRESHOLD_CM) {
      Serial.println("🚨 Left opening detected! Initiating turn...");
      targetAngle = mpu.getAngleZ() + 90.0; // Adjust target angle 90 degrees left
      myServo.write(SERVO_LEFT);            // Steer wheels left
      ledcWrite(ENA, TURN_SPEED);
      currentState = TURNING;
    }
  }

  // --------------------------------------------------
  // State 2: Turning until reaching 90 degrees
  // --------------------------------------------------
  else if (currentState == TURNING) {
    float currentAngle = mpu.getAngleZ();
    float remainingError = abs(currentAngle - targetAngle);

    // Check if turn target reached within tolerance (< 2.0 degrees)
    if (remainingError < 2.0) {
      Serial.println("🎯 90-degree turn completed successfully!");
      stopRobot();
      currentState = STOPPED;
    }
  }

  // --------------------------------------------------
  // State 3: Stopped
  // --------------------------------------------------
  else if (currentState == STOPPED) {
    // Robot remains idle here
  }

  delay(10); 
}
