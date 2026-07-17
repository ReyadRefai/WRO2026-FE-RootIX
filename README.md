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

The table below outlines the comprehensive hardware configuration integrated into our autonomous vehicle. It details the quantity, economic budgeting (in ILS), technical specifications, visual reference, and the exact engineering utility of each component within our self-driving navigation system:

| # | Component Name | 📷 Visual | Qty | Unit Price | Key Technical Specifications | Autonomous Engineering Value (WRO Use-Case) |
| :-: | :--- | :-: | :-: | :-: | :--- | :--- |
| **1** | **L298N Dual H-Bridge Motor Shield** | <img width="1080" height="1035" alt="اتش بردج" src="https://github.com/user-attachments/assets/1fab9064-c36f-424b-a551-58cd485afce2"/> | 1 | 19 ILS | • Dual H-bridge motor driver.<br>• 6V–15V motor supply voltage.<br>• 2A max current per channel.<br>• 0%–100% PWM duty range.<br>• Built-in 5V regulator. | • **Current Amplification & Logic Protection:** Bridges the gap between the low-current microcontroller and the high-current DC motors.<br>• **Velocity Control:** Regulates motor speed via PWM signals and controls directional rotation (forward/reverse) while isolating the processing unit from inductive voltage spikes. |
| **2** | **Premium Male-to-Female Jumper Wires** | <img width="621" height="365" alt="لقطة شاشة 2026-07-16 204405" src="https://github.com/user-attachments/assets/994ea54f-c517-466a-b2e8-91ab80996455" />| 1 Pack (40 pcs) | 16 ILS | • 20cm length ribbon cable.<br>• Standard 2.54mm pitch headers.<br>• Male-to-Female configuration.<br>• 10 color-coded segments. | • **Circuit Prototyping & Diagnostics:** Establishes reliable point-to-point connections between sensor boards and the microcontroller.<br>• **Color-Coded Wire Mapping:** Streamlines trackside diagnostics, reduces wiring errors during assembly, and allows swift component replacement without soldering. |
| **3** | **Premium Female-to-Female Jumper Wires** | <img width="542" height="489" alt="لقطة شاشة 2026-07-16 204200" src="https://github.com/user-attachments/assets/0f5c853b-2069-454e-abb9-f384f0519314" /> | 1 Pack (40 pcs) | 16 ILS | • 20cm length ribbon cable.<br>• Standard 2.54mm socket pitch.<br>• Female-to-Female configuration.<br>• Flexible PVC insulation. | • **Inter-Module Connectivity:** Connects components utilizing male pin headers directly to the main expansion shields.<br>• **Vibration-Resistant Sockets:** High-friction contacts ensure stable connection density under steady vehicle movement, preventing intermittent signal drops. |
| **4** | **400 Tie-Point Half-Size Breadboard (ESP Host Platform)** | <img width="647" height="447" alt="بورد " src="https://github.com/user-attachments/assets/e1194e10-bcc3-41af-b6d0-c00d9a977f55" /> | 1 | 9 ILS | • 400 tie-in points with standard 2.54mm pin spacing.<br>• Dual power distribution rails.<br>• Self-adhesive backing. | • **Solderless Integration Deck:** Hosts the secondary microcontroller (ESP32) and routes its GPIO pins cleanly.<br>• **Power Rail Segregation:** Distributes regulated 3.3V and 5V lines to adjacent sensor circuits, ensuring organized power distribution during development. |
| **5** | **18650 Li-Ion Battery Cells** | <img width="288" height="313" alt="بطارية 2" src="https://github.com/user-attachments/assets/4d17b0bc-e607-49c6-9436-c8f4b6c1a3a1" />| 2 | 15 ILS | • Rechargeable Lithium-Ion chemistry.<br>• 18650 cylindrical form factor.<br>• 3.7V nominal voltage.<br>• High energy density. | • **High-Density DC Power Source:** Supplies a reliable, lightweight power base optimized for mobile robotics.<br>• **Stable Discharge Profile:** Maintains a consistent voltage curve during operational runs, ensuring predictable motor performance compared to standard alkaline alternatives. |
| **6** | **Lithium Battery 18650 Charger Module Type-C 15W 3A** | <img width="263" height="224" alt="WhatsApp Image 2026-07-16 at 8 40 07 PM" src="https://github.com/user-attachments/assets/14a6e8f6-ffab-4967-a0b2-a4e1ab270e29" /> | 1 | 35 ILS | • Type-C charging interface.<br>• Seamless UPS power switching.<br>• Configurable step-up output.<br>• Integrated cell protection. | • **Voltage Step-Up Regulation:** Elevates the battery base voltage to the required system operation thresholds.<br>• **Uninterrupted Power Supply (UPS):** Allows seamless switching between USB configuration power and onboard battery power without resetting the active processors. |
| **7** | **VL53L0X Time-of-Flight (ToF) Laser Distance Sensor** | *[Drag Image Here]* | 3 | - ILS | • 940nm VCSEL infrared laser.<br>• Time-of-Flight (ToF) architecture.<br>• Ranging up to 2.0m.<br>• I2C Interface communication. | • **Distance Measurement via Ranging:** Measures absolute distances using light flight-time, ensuring tracking accuracy unaffected by ambient light or target surface colors.<br>• **3-Axis Obstacle Monitoring:** Configured in a front/left/right array to provide real-time distance data for obstacle avoidance and lane centering. |
| **8** | **TCA9548A I2C 8-Channel Multiplexer Board** | *[Drag Image Here]* | 1 | - ILS | • 1-to-8 bidirectional switches.<br>• Configurable I2C address (0x70-0x77).<br>• 3V–5V logic level tolerant. | • **I2C Bus Conflict Resolution:** Resolves physical address conflicts by allowing multiple identical VL53L0X sensors (which share a fixed default address) to be addressed independently on isolated sub-buses. |
| **9** | **Raspberry Pi Camera Module 3** | *[Drag Image Here]* | 1 | - ILS | • Sony IMX708 11.9MP CMOS sensor.<br>• Phase Detection Autofocus (PDAF).<br>• CSI-2 serial data interface. | • **Visual Optical Ingestion:** Captures high-resolution frames of track lanes and signaling elements for computer vision analysis.<br>• **Dynamic Auto-Focus Stabilization:** PDAF hardware maintains image sharpness during vehicle acceleration and tracking maneuvers. |
| **10** | **Raspberry Pi 5 Single Board Computer (SBC)** | *[Drag Image Here]* | 1 | 1050 ILS | • Broadcom BCM2712 2.4GHz quad-core CPU.<br>• LPDDR4X high-speed SDRAM.<br>• Dual 4-lane MIPI transceivers. | • **High-Level Computational Unit:** Executes the primary computer vision framework (OpenCV) for path planning, color extraction, and object tracking in real-time.<br>• **Multi-Threaded Framework Processing:** Processes high-frame-rate visual feeds to minimize instruction latency during navigation decisions. |
| **11** | **XL4016 200W Step-Down (Buck) Converter** | *[Drag Image Here]* | 2 | 55 ILS | • DC-to-DC non-isolated buck regulator.<br>• Input: 4V–40V, Output: 1.25V–36V.<br>• Continuous output current up to 5A. | • **Dual Rail Voltage Isolation:** Implements parallel buck regulation to down-step battery voltage. One unit supplies stable 5V/5A power to the Raspberry Pi 5 to prevent under-voltage throttling, while the second independently powers the steering servo to isolate actuator noise. |
| **12** | **MPU-6050 6-DOF Accelerometer and Gyroscope Sensor** | *[Drag Image Here]* | 1 | 45 ILS | • Onboard Digital Motion Processor™ (DMP™).<br>• Tri-Axis angular rate sensor (gyro) up to $\pm2000^{\circ}/\text{s}$.<br>• Tri-Axis accelerometer up to $\pm16\text{g}$.<br>• Input Voltage: 2.3V–3.4V DC.<br>• I2C digital-output interface format. | • **Real-Time Orientation Tracking:** Provides precise angular velocity updates along the Z-axis (yaw rate) to track the robot's heading during turns, compensating for optical blind spots.<br>• **Hardware Sensor Fusion:** Utilizes the integrated DMP to execute runtime orientation filtering, offloading mathematical computation from the main controller. |
| **13** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **14** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **15** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **16** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **17** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **18** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **19** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |
| **20** | *[Component Name]* | *[Drag Image Here]* | - | - ILS | • Specifications. | • WRO Use-Case benefit. |













