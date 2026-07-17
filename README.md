# WRO2026-FE-RootIX
<img width="1254" height="1254" alt="rootix" src="https://github.com/user-attachments/assets/05332181-9b1f-4411-a81d-efff4dd22a71" />

# Hello! we are RootIX team. 
# WRO - Future Engineers-Robotics Project Documentation

## 🚀 Project Overview

Welcome to the official repository of team **RootiX**! We are Mechatronics Engineering students from **Birzeit University**, united by a shared passion for robotics, automation, and intelligent systems. This repository serves as a comprehensive chronicle of our development journey for the **WRO Future Engineers** competition. Utilizing a ready-made hardware kit as our physical platform, our engineering focus was driven by advanced programming, software architecture, and embedded systems control developed entirely on our laptops. Within these pages, we thoroughly document our complete software lifecycle, highlighting how we transformed hardware into a smart autonomous vehicle. From writing control algorithms and integrating sensors to the final crucial stages of system calibration and rigorous performance testing on the track, we invite you to explore our engineering process.


# Team Members
- 🔹 Israa Anbar
- 🔹 Reyad Refai


## 🛠️ Hardware Platform & Mechanical Base

To build our autonomous vehicle, we started with a high-performance, rear-wheel-drive (RWD) robotic chassis kit featuring real-world **Ackermann steering geometry**. This physical platform provides the perfect mechanical stability and precise steering control required to navigate the WRO track.

### 📦 Base Kit Components (Before Additions):
* 🔹 **Chassis Plates:** Lightweight, high-durability black structural plates that serve as the main frame for mounting our controllers and sensors.
* 🔹 **Steering System:** Front-wheel steering knuckles equipped with adjustable metal linkages (ball joints) for precise alignment.
* 🔹 **Actuators & Propulsion:**
  * **Drive Motor:** High-torque DC metal gear motor for reliable rear-wheel propulsion.
  * **Steering Servo:** High-precision standard servo motor dedicated to controlling the front-wheel steering angle.
* 🔹 **Tires & Traction:** Four high-grip rubber tires with red alloy-style rims, designed to provide optimal friction and prevent slipping on sharp turns.
* 🔹 **Safety & Protection:** A dense front foam bumper to absorb impacts and protect the core electronics during testing.
* 🔹 **Hardware & Assembly:** Precision bearings, brass hexagonal standoffs, steel fasteners, and a heavy-duty power switch.

### 📷 Unboxing & Raw Kit Components
Below is a showcase of our raw mechanical components and chassis parts before assembly and electronics integration:
<img width="1132" height="1600" alt="شصي" src="https://github.com/user-attachments/assets/346c0cc0-aaae-4262-85e9-74e1126f7c15" />






## 📊 Hardware Bill of Materials (BOM) & System Integration

The table below outlines the comprehensive hardware configuration integrated into our autonomous vehicle. It details the quantity, economic budgeting (in ILS), technical specifications, visual reference, and the exact high-level engineering utility of each component within our self-driving navigation system architecture:

| # | Component Name | 📷 Visual | Qty | Unit Price | Key Technical Specifications | Autonomous Engineering Value (WRO Use-Case) |
| :-: | :--- | :-: | :-: | :-: | :--- | :--- |
| **1** | **L298N Dual H-Bridge Motor Shield** | <img width="1080" height="1035" alt="اتش بردج" src="https://github.com/user-attachments/assets/1fab9064-c36f-424b-a551-58cd485afce2"/> | 1 | 19 ILS | • Dual H-bridge motor driver.<br>• 6V–15V motor supply voltage.<br>• 2A max current per channel.<br>• 0%–100% PWM duty range.<br>• Built-in 5V regulator. | • **Current Amplification & Logic Isolation:** Bridges the gap between the low-current microcontroller and high-current DC motors while providing inductive back-EMF spike isolation.<br>• **Velocity Control Peripherals:** Regulates differential motor speed via hardware PWM signals and manages direction configurations without processing unit throttling. |
| **2** | **Premium Male-to-Female Jumper Wires** | <img width="621" height="365" alt="لقطة شاشة 2026-07-16 204405" src="https://github.com/user-attachments/assets/994ea54f-c517-466a-b2e8-91ab80996455" />| 1 Pack | 16 ILS | • 20cm length ribbon cable.<br>• Standard 2.54mm pitch headers.<br>• Male-to-Female configuration.<br>• 10 color-coded segments. | • **High-Fidelity Signal Routing:** Establishes low-resistance, point-to-point logic pathways between discrete sensor modules and expansion headers.<br>• **Structured Diagnostic Bus:** Uses standardized color-coding to minimize wiring topology mapping errors and streamline trackside debugging during rapid prototyping phases. |
| **3** | **Premium Female-to-Female Jumper Wires** | <img width="542" height="489" alt="لقطة شاشة 2026-07-16 204200" src="https://github.com/user-attachments/assets/0f5c853b-2069-454e-abb9-f384f0519314" /> | 1 Pack | 16 ILS | • 20cm length ribbon cable.<br>• Standard 2.54mm socket pitch.<br>• Female-to-Female configuration.<br>• Flexible PVC insulation. | • **Inter-Module Bus Connectivity:** Interconnects standard male pin header arrays directly across physical chassis boundaries.<br>• **Vibration-Resistant Contact Density:** High-friction physical socket coupling ensures data bus integrity under high mechanical vibration and transient cornering loads during high-speed runs. |
| **4** | **400 Tie-Point Half-Size Breadboard** | <img width="647" height="447" alt="بورد " src="https://github.com/user-attachments/assets/e1194e10-bcc3-41af-b6d0-c00d9a977f55" /> | 1 | 9 ILS | • 400 tie-in points with standard 2.54mm pin spacing.<br>• Dual power distribution rails.<br>• Self-adhesive backing. | • **Solderless System Integration Deck:** Serves as a modular physical host platform for expansion modules and peripheral pull-up/pull-down resistor networks.<br>• **Power Rail Segregation:** Isolates 3.3V and 5V power domains systematically to eliminate capacitive cross-talk between adjacent signal buses. |
| **5** | **18650 Li-Ion Battery Cells** | <img width="288" height="313" alt="بطارية 2" src="https://github.com/user-attachments/assets/4d17b0bc-e607-49c6-9436-c8f4b6c1a3a1" />| 2 | 15 ILS | • Rechargeable Lithium-Ion chemistry.<br>• 18650 cylindrical form factor.<br>• 3.7V nominal voltage.<br>• High energy density. | • **Low-Impedance Electrochemical Power Source:** Provides a lightweight, high energy-density power plant optimized for autonomous mobile platforms.<br>• **Flat Discharge Curve Integration:** Guarantees a sustained operational current supply, maintaining uniform motor torque characteristics and repeatable kinematic mapping over extended run-times. |
| **6** | **Type-C 15W 3A Li-Ion Battery Charger & UPS Module** | <img width="263" height="224" alt="WhatsApp Image 2026-07-16 at 8 40 07 PM" src="https://github.com/user-attachments/assets/14a6e8f6-ffab-4967-a0b2-a4e1ab270e29" /> | 1 | 35 ILS | • Type-C charging interface.<br>• Seamless UPS power switching.<br>• Configurable step-up output.<br>• Integrated cell protection. | • **Continuous Telemetry Power Switching (UPS):** Allows the vehicle to transition seamlessly between external USB debugging power and internal battery power without inducing processor brownouts.<br>• **Integrated Voltage Regulation:** Coordinates dynamic step-up power conversions to meet structural systemic voltage requirements. |
| **7** | **VL53L0X Time-of-Flight (ToF) Laser Sensor** |<img width="364" height="246" alt="لقطة شاشة 2026-07-17 133549" src="https://github.com/user-attachments/assets/a3396e91-1c02-4613-b22c-40824dbe5b95" /> | 3 | - 22 | • 940nm VCSEL infrared laser.<br>• Time-of-Flight (ToF) architecture.<br>• Ranging up to 2.0m.<br>• I2C Interface communication. | • **Lambertian-Independent Spatial Mapping:** Executes ultra-precise distance evaluation via photon flight-time measurements, generating target reflectivity-independent and color-blind distance tracking data.<br>• **Multi-Axis Spatial Obstacle Avoidance:** Deployed in a tri-directional array for sub-millimetric lane centering and real-time collision avoidance vector calculations. |
| **8** | **TCA9548A I2C 8-Channel Multiplexer Board** | <img width="310" height="232" alt="لقطة شاشة 2026-07-17 133747" src="https://github.com/user-attachments/assets/adcbb693-9afc-4352-beaa-57373da6f349" /> | 1 | - ILS | • 1-to-8 bidirectional switches.<br>• Configurable I2C address (0x70-0x77).<br>• 3V–5V logic level tolerant. | • **I2C Bus Hardware Conflict Resolution:** Resolves static physical hardware address overlapping by mapping multiple identical address sensors onto isolated, individually selectable sub-buses.<br>• **Synchronous Spatial Polling:** Enables deterministic sequential sampling of multi-sensor arrays through a single primary microcontroller hardware master I2C interface. |
| **9** | **Raspberry Pi Camera Module 3** | <img width="355" height="265" alt="لقطة شاشة 2026-07-17 134041" src="https://github.com/user-attachments/assets/3218c015-ea3f-42bf-a40e-342b7aa5ffed" /> | 1 | - ILS | • Sony IMX708 11.9MP CMOS sensor.<br>• Phase Detection Autofocus (PDAF).<br>• CSI-2 serial data interface. | • **Optical Ingestion Framework:** Captures high-frame-rate, high-definition visual feeds for localized processing and path-planning algorithms.<br>• **Phase Detection Autofocus Optimization:** PDAF mechanisms preserve optical edge clarity during abrupt mechanical transients, ensuring uninterrupted lane tracking and color-space qualification. |
| **10** | **Raspberry Pi 5 Single Board Computer (SBC)** | <img width="1080" height="1215" alt="ريزباري" src="https://github.com/user-attachments/assets/3c09fe14-3e5a-4198-a920-bf60aef37a67" /> | 1 | 1050 ILS | • Broadcom BCM2712 2.4GHz quad-core CPU.<br>• LPDDR4X high-speed SDRAM.<br>• Dual 4-lane MIPI transceivers. | • **High-Level Heterogeneous Computing Platform:** Executes computer vision operations (OpenCV), processes color-space segmentations, calculates localized trajectory matrices, and maintains the primary state-machine control loop.<br>• **Parallel Algorithm Multithreading:** Handles multi-threaded asynchronous sensor parsing pipelines to minimize overall decision-to-actuation system latency. |
| **11** | **XL4016 200W Step-Down (Buck) Converter** | <img width="345" height="300" alt="لقطة شاشة 2026-07-17 134233" src="https://github.com/user-attachments/assets/9212cf59-7ad2-4c21-ba88-c74c2edb9db6" /> | 2 | 55 ILS | • DC-to-DC non-isolated buck regulator.<br>• Input: 4V–40V, Output: 1.25V–36V.<br>• Continuous output current up to 5A. | • **Dynamic High-Current Domain Isolation:** Parallel-configured synchronous buck regulators isolate logic and actuator power domains. One module supplies continuous stable power to the SBC to prevent thermal/voltage throttling, while the other dampens transient actuator noise. |
| **12** | **MPU-6050 6-DOF Accelerometer & Gyroscope** | <img width="321" height="240" alt="لقطة شاشة 2026-07-17 180256" src="https://github.com/user-attachments/assets/1029384d-1836-474d-bbfd-61604cb985ce" /> | 1 | 45 ILS | • Onboard Digital Motion Processor™ (DMP™).<br>• Tri-Axis angular rate sensor (gyro) up to $\pm2000^{\circ}/\text{s}$.<br>• Tri-Axis accelerometer up to $\pm16\text{g}$.<br>• Input Voltage: 2.3V–3.4V DC.<br>• I2C digital-output interface format. | • **Inertial Dead Reckoning & Odometry Tracking:** Provides real-time angular velocity feedback across the Z-axis (yaw rate) to accurately monitor vehicle orientation changes during high-speed maneuvers.<br>• **Hardware Sensor Fusion Acceleration:** Offloads computationally intensive motion-filtering calculations from the primary host by utilizing the integrated DMP firmware. |
| **13** | **L7805CV Positive Fixed Voltage Regulator** | <img width="872" height="834" alt="منظم جهد" src="https://github.com/user-attachments/assets/27fed99f-d471-4803-a0e2-cd4c73ec22f1" /> | 2 | 5 ILS | • Fixed 5V positive voltage regulator.<br>• Maximum output current up to 1.5A.<br>• Built-in internal thermal overload protection.<br>• TO-220 standard package. | • **Ultra-Low Ripple Analog Reference Rail:** Regulates transient DC voltage profiles to generate a dedicated, ripple-free 5V reference line for low-power logical sub-circuits.<br>• **EMI Cross-Talk Mitigation:** Shields sensitive digital processing communication lines from electromagnetic fields generated by high-current motor pathways. |
| **14** | **ESP32 Development Board (38-Pin NodeMCU-32S Version)** | <img width="1045" height="716" alt="لقطة شاشة 2026-07-17 201337" src="https://github.com/user-attachments/assets/f6debb63-7b38-40cc-9a55-4545388d4e9b" /> | 1 | 30 ILS | • Tensilica Xtensa dual-core 32-bit LX6 CPU.<br>• 38-pin layout with dedicated top-side 5V logic input.<br>• Up to 240MHz clock frequency & 520KB SRAM.<br>• Multi-channel hardware PWM & ADC peripherals.<br>• Standard UART/I2C/SPI communication interfaces. | • **Deterministic Low-Level Actuation Core:** Dedicated exclusively to hardware-timed tasks, executing p## 🧠 System Architecture & Communication Protocol






Our autonomous vehicle utilizes a **Distributed Computing Architecture** to split high-level cognitive tasks from low-level real-time actuation, ensuring zero-latency responses during high-speed navigation.

### 📊 Hardware Task Allocation
*   **High-Level Master (Raspberry Pi 5):** Handles intensive Computer Vision (OpenCV), multi-object detection (Red/Green pillars), spatial path planning, and global state-machine execution.
*   **Low-Level Slave (ESP32 NodeMCU):** Executes real-time hardware control, including hardware-timed PWM generation for the drive motor and steering servo, sensor polling (ToF via I2C), and safety-critical fallback routines.

### 🔌 Inter-Processor Communication (IPC) via UART
The Raspberry Pi 5 and ESP32 communicate via a high-speed **UART (Serial) interface** operating at a baud rate of `115200 bps`. To prevent data corruption and ensure deterministic execution, we developed a custom lightweight, fixed-overhead packet protocol. 

**Packet Data Structure (Master to Slave):**
| Byte Offset | Field | Type | Description |
|---|---|---|---|
| 0x00 | Header | uint8_t | Synchronization byte (`0xAA`) |
| 0x01 | Steering Angle | int8_t | Target Ackermann steering angle (-45° to +45°) |
| 0x02 | Throttle Velocity | int8_t | Target motor speed percentage (-100% to +100%) |
| 0x03 | Mode State | uint8_t | System State (0: Idle, 1: Open Challenge, 2: Obstacle, 3: Parking) |
| 0x04 | Checksum | uint8_t | XOR verification byte for error detection |recise sub-millisecond PWM scaling for steering servos and velocity control loop execution.<br>• **Hardware Interrupt Sensor Ingestion:** Offloads continuous low-level data acquisition tasks from the Raspberry Pi 5 via hardware interrupts, guaranteeing deterministic sampling. |







## 🤖 Autonomous Navigation & Vision Pipelines

Our software architecture relies on dynamic state-machines that adapt to the specific requirements of each race category, using feedback loops and advanced computer vision.

### 1. Wall-Following & Lane Centering (Open Challenge)
In the Open Challenge, the vehicle maintains an optimal center trajectory within shifting walls using a closed-loop feedback mechanism. The distance inputs gathered from the VL53L0X Time-of-Flight (ToF) laser sensors are fed into a continuous Proportional-Integral-Derivative (PID) Controller to calculate corrective steering adjustments.

The error, e(t), is defined as the Cross-Track Error (CTE):
Error = Distance_Left - Distance_Right

The control law continuously updates the steering angle to minimize this error, preventing erratic oscillations and ensuring fluid cornering at maximum velocities.

### 2. Color-Based Obstacle Avoidance (Obstacle Challenge)
For dynamic obstacle navigation, the Raspberry Pi Camera Module 3 captures raw frames at 60 FPS. The vision pipeline processes images in the following deterministic sequence:

1. **Color Space Conversion:** BGR frames are converted to the HSV (Hue, Saturation, Value) color space to eliminate sensitivity to ambient track lighting variances.
2. **Thresholding & Masking:** Dual-band logical masking isolates Red and Green color profiles.
3. **Contour Extraction:** Spatial bounding boxes estimate the object's centroid and distance based on pixel-area scaling.
4. **Ackermann Decoupling:** 
   * If a **Green contour** is detected, the path planner shifts the target waypoint to the *left* of the obstacle.
   * If a **Red contour** is detected, the path planner shifts the target waypoint to the *right* of the obstacle.

### 3. Precision Parallel Parking (Magenta Finish Line)
Upon completing the mandatory 3 laps, the high-level state machine switches to **Finish/Parking Mode**. When the camera detects a dense concentration of **Magenta pixels** bounding the designated parking zone, it triggers an open-loop odometry sequence:

1. The vehicle aligns parallel to the parking bay entrance using side ToF feedback.
2. It executes a sharp, calculated reverse turn into the bay.
3. Counter-steering is applied to straighten the chassis once the rear ToF registers proximity to the back wall.
4. The system cuts power and enters a permanent hardware-brake loop without exceeding boundary tolerances.
٥.









