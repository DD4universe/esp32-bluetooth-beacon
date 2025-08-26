# ESP32 Bluetooth Beacon 🚀

This project transforms an **ESP32** into a **Bluetooth Low Energy (BLE) Beacon** (iBeacon/Eddystone) — using only the ESP32 and a USB cable. No external sensors or wiring required.  

With this code, your ESP32 continuously broadcasts BLE advertisement packets that can be detected by any smartphone using a free BLE scanner app.

---

## 📌 Features
- Works with **any ESP32 Dev board**  
- No external components required (just USB power)  
- Broadcasts as an **iBeacon** with customizable UUID, Major, and Minor values  
- Detectable on iOS and Android using BLE scanner apps  
- Super lightweight → runs forever in low-power mode  

---

## 🛠 Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)  
- ESP32 Board Package installed  
  - Add this URL in Arduino IDE → Preferences → Additional Boards Manager URLs:  
    ```
    https://dl.espressif.com/dl/package_esp32_index.json
    ```
- BLE scanner app on your phone:  
  - [nRF Connect (Android/iOS)](https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-mobile)  
  - [Beacon Scanner (Android)](https://play.google.com/store/apps/details?id=com.bridou_n.beaconscanner)  
  - [LightBlue Explorer (iOS)](https://apps.apple.com/us/app/lightblue/id557428110)  

---

## 📂 Project Files
- `ESP32_Beacon.ino` → Main Arduino sketch

---

## 🚀 Getting Started
1. Open Arduino IDE  
2. Select **ESP32 Dev Module** as your board  
3. Select the correct **Port** (after installing USB drivers if needed)  
4. Upload the code to ESP32  
5. Open **Serial Monitor (115200 baud)** → you should see:  
6. Open the BLE scanner app on your phone → scan for beacons → your ESP32 should appear!  

---

## ✨ Customization
You can change the UUID, Major, and Minor values in the code:  
```cpp
#define BEACON_UUID "12345678-1234-5678-1234-56789abcdef0"
oBeacon.setMajor(1);
oBeacon.setMinor(1);
