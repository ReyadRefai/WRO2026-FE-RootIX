#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <ESP32Servo.h> 
#include <MPU6050_light.h> 

// ------------------------------------------------------------------------
// 1. Pin Definitions and I2C Setup
// ------------------------------------------------------------------------
#define SERVO_PIN 18 

#define IN1 25    
#define IN2 26    
#define ENA 27    // PWM speed control pin

#define TCAADDR 0x70        // I2C multiplexer address
#define TOF_RIGHT_CH 1      // Channel 1: Right sensor only

#define SDA_IMU 4           // Direct MPU6050 connection
#define SCL_IMU 5

// ------------------------------------------------------------------------
// 2. Speed and Angle Settings
// ------------------------------------------------------------------------
const int MOTOR_SPEED = 200;          // Motor speed
const int SERVO_STRAIGHT = 70;        // Straight angle

// 💡 Adjust right turn direction 
const int SERVO_RIGHT_35 = 70 - 45;   // Right turn angle (25°)

const int RIGHT_THRESHOLD_MM = 400;   // 40 cm threshold (400 mm)

// ------------------------------------------------------------------------
// 3. Object Creation
// ------------------------------------------------------------------------
Servo myServo;
Adafruit_VL53L0X tofRight = Adafruit_VL53L0X();

TwoWire I2C_IMU = TwoWire(1);         // Isolated second I2C bus for IMU
MPU6050 mpu(I2C_IMU);                  

bool isTurnCompleted = false;         // Flag to stop the robot after turning

void tcaselect(uint8_t i) {
  if (i > 7) return; 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
  delay(2);
}

// ========================================================================
// Setup
// ========================================================================
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n==================================================");
  Serial.println("   🧪 IMU Right Turn Test");
  Serial.println("==================================================");

  // 1. Setup servo and point it straight
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myServo.setPeriodHertz(50); 
  myServo.attach(SERVO_PIN); 
  myServo.write(SERVO_STRAIGHT);

  // 2. Setup motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  ledcAttach(ENA, 5000, 8); 

  // 3. Enable first I2C bus (Wire) for multiplexer (GPIO 21, 22)
  Wire.begin(21, 22);

  // 4. Enable second I2C bus (Wire1) for IMU (GPIO 4, 5)
  I2C_IMU.begin(SDA_IMU, SCL_IMU);

  // 5. Initialize and calibrate MPU6050
  byte status = mpu.begin();
  if (status != 0) {
    Serial.print("❌ Failed to connect to IMU! Error code: ");
    Serial.println(status);
    while (1) delay(1000);
  }

  Serial.println("⏳ Calibrating IMU... (Please keep the robot still)");
  delay(1500);
  mpu.calcOffsets();
  Serial.println("✅ IMU is ready.");

  // 6. Initialize right sensor
  tcaselect(TOF_RIGHT_CH);
  if (!tofRight.begin()) {
    Serial.println("❌ Failed to start right sensor!");
  } else {
    Serial.println("✅ Right sensor started successfully.");
  }

  // 7. Start motor immediately to move forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  ledcWrite(ENA, MOTOR_SPEED);
  Serial.println("▶️ Motor is running to move forward...");

  delay(500); 
}

// ========================================================================
// Main Loop
// ========================================================================
void loop() {
  // If the robot has completed the 90-degree turn, stop the motor completely
  if (isTurnCompleted) {
    ledcWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    myServo.write(SERVO_STRAIGHT);
    return;
  }

  // Update IMU data
  mpu.update();

  // 1. Read right sensor distance
  tcaselect(TOF_RIGHT_CH);
  VL53L0X_RangingMeasurementData_t measureRight;
  tofRight.rangingTest(&measureRight, false);

  int rightDistance = measureRight.RangeMilliMeter;
  bool rightValid = (measureRight.RangeStatus != 4);

  Serial.print("📏 Right sensor distance: ");
  Serial.print(rightDistance);
  Serial.println(" mm");

  // 2. Check: If the right distance is greater than 400 mm (40 cm)
  if (rightValid && rightDistance > RIGHT_THRESHOLD_MM) {
    Serial.println("🚨 Distance is > 40 cm! Tilting servo to the right...");

    // A. Steer servo to the right immediately
    myServo.write(SERVO_RIGHT_35);

    // B. Record IMU starting angle
    mpu.update();
    float startAngle = mpu.getAngleZ();
    float currentTurnedAngle = 0.0;

    // C. Turn tracking loop (motor keeps running until reaching 90 degrees)
    while (abs(currentTurnedAngle) < 90.0) {
      mpu.update();
      currentTurnedAngle = mpu.getAngleZ() - startAngle;

      Serial.print("🔄 Current turn angle: ");
      Serial.print(abs(currentTurnedAngle), 1);
      Serial.println("° / 90.0°");

      delay(10); 
    }

    Serial.println("🎯 Full 90-degree turn completed! Stopping motor completely...");

    // D. Stop motor completely
    ledcWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    // E. Return servo to straight position
    myServo.write(SERVO_STRAIGHT);

    // F. Lock movement flag to keep the robot stopped
    isTurnCompleted = true;
  }

  delay(30); 
}
