# Soil Moisture Device 🌱

A simple and low-cost soil moisture sensor using Arduino to help you monitor plant hydration levels. Originally published on [Instructables](https://www.instructables.com/Soil-Moisture-Device/), this project is designed for makers, gardeners, and beginners in electronics.

---

## 🧰 Bill of Materials

| Item                   | Quantity | Notes                          |
|------------------------|----------|--------------------------------|
| Arduino Nano           | 1        | Or any compatible board        |
| Soil Moisture Sensor   | 1        | Capacitive sensor preferred    |
| OLED Display (0.96")   | 1        | I2C interface                  |
| Wires & Breadboard     | —        | Jumper wires, etc.             |
| 3D Printed Case        | 1        | Files included in `3d-files/`  |
| USB Power Supply       | 1        | Or battery pack (5V)           |

---

## 🧠 Features

- Real-time soil moisture readings on OLED display
- Compact, portable design
- Optional 3D printed enclosure
- Easy to assemble and modify

---

## ⚡ Circuit Diagram

Find the diagram in `image/Wiring_bb.png`


**Connections:**

| Component          | Arduino Pin |
|-------------------|-------------|
| Soil Sensor (A0)   | A0          |
| OLED SDA           | A4          |
| OLED SCL           | A5          |
| VCC & GND          | 5V & GND    |

---

## 🛠️ Assembly Instructions

1. Wire the components as shown in the circuit diagram.
2. Upload the code in `arduino/Moisture_Device.ino` using the Arduino IDE.
3. Power the device via USB or battery.
4. Optional: Print the enclosure using the `.stl` files in `3d-files/` and assemble it.

---

## 👀 Usage

Once powered, the OLED display shows the current moisture level. Insert the sensor into the soil near the plant's roots for the most accurate readings.

---

## 🧱 3D Files

Located in the [`3d-files/`](./3d-files/) folder:

- `base.stl`: Base of the enclosure
- `lid.stl`: Cover of the base
- `OLED Front`: Cover of the Monitor

Use any FDM printer with PLA or PETG for best results.

---

## 🧑‍💻 Code

Arduino sketch is in the [`arduino/`](./arduino/) directory.

```cpp
// Moisture_Device.ino
// Upload this code using Arduino IDE
```
## 📜 License
This project is licensed under the MIT License.

## 🙌 Credits
Created by Ioannis Mastoras
