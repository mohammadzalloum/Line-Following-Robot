# 🤖 Line-Following Robot

<img src="https://github.com/user-attachments/assets/4b296f53-bb9e-4348-a93a-90e985b5ab96" alt="Robot image" style="width: 400px; max-width: 100%; height: auto;" />



A **Line-Following Robot** designed to detect and follow black lines on a white surface using a reflectance sensor array and controlled via an ESP32 microcontroller. This project demonstrates the fundamentals of robotics, embedded systems, and sensor-based navigation.

---

## 📌 Project Overview

This robot uses a QTR reflectance sensor to detect the path and adjusts its motors accordingly to follow the line. It is powered by a LiPo battery and controlled by an ESP32 development board. The compact and modular design allows for easy expansion and customization.

---

## 🧰 Components Used

| Component | Description |
|----------|-------------|
| 🔘 **QTR-8RC Reflectance Sensor Array** | For detecting line contrast (black/white) |
| ⚙️ **N20 6V 200 RPM DC Motors** | High-torque motors for movement |
| 🔋 **XL4015 DC-DC Step-down Module** | Adjustable power supply for voltage regulation |
| 🔋 **LiPower LiPo Battery 2S 7.4V 550mAh (XT60 35C)** | Lightweight battery for powering components |
| 🔌 **1P2T Toggle Switch** | For turning power on/off |
| 🛞 **FingerTech Mini-Sumo Wheels (Red, pair)** | High-grip wheels for stability |
| 🧵 **40 Male-to-Male Jumper Wires (10cm)** | For connections between modules |
| 🔄 **Pololu DRV8833 Motor Driver** | Dual H-Bridge motor driver for controlling motors |
| 📡 **ESP32 NodeMCU ESP-WROOM-32E** | Wi-Fi enabled microcontroller for core logic |
| 🔌 **iMAX B6AC Charger** | To safely charge the LiPo battery |

---

## ⚙️ How It Works

1. The QTR-8RC sensor array detects the reflectivity of the surface.
2. Based on the sensor data, the ESP32 processes logic to steer the robot.
3. Motor speeds are adjusted via the DRV8833 driver to keep the robot on the line.
4. The step-down module ensures consistent voltage to all components.
5. The toggle switch allows manual power control for safety and testing.

---

## 📦 Status

✅ Hardware Assembly: Completed  
✅ Basic Line Following Algorithm: Implemented  
🔧 Advanced Features (PID, Bluetooth, etc.): Coming Soon

---

## 📸 Images & Videos

Stay tuned for more media showcasing the robot in action!

---

## 📬 Contact

For questions or collaboration:  
📧 mohammad.zalloum098@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/mohammad-zalloum-36158323b/)  
🌐 [Portfolio](https://mohammadzalloum.dev)

