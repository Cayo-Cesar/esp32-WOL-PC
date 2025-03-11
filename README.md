# Wake-on-LAN with ESP32 and Blynk

This project allows you to remotely power on a device using the **Wake-on-LAN (WOL)** protocol. The Magic Packet is sent via a button on the **Blynk** app, and the hardware used is an **ESP32**.

---

## **Features**
- Sends a Magic Packet to wake up a device on the local network.
- Integration with Blynk for remote control via the app.
- Easy configuration of the target device's MAC address.

---

## **Requirements**
### Hardware
- ESP32 (any variant with Wi-Fi).
- Wi-Fi connection.

### Software
- Blynk library (`BlynkSimpleEsp32.h`).
- Wi-Fi library (`WiFi.h`).
- UDP library (`WiFiUdp.h`).

### Configuration
- MAC address of the target device.
- Blynk authentication token.
- Wi-Fi network credentials.

---

## **How It Works**
1. The ESP32 connects to the Wi-Fi network and Blynk.
2. When the button on the Blynk app is pressed, the ESP32 sends a **Magic Packet** to the specified MAC address.
3. The device with the corresponding MAC address receives the packet and powers on (if Wake-on-LAN is enabled on the device).

---

## **Installation**
1. **Install Required Libraries**:
   - In the Arduino IDE, install the following libraries:
     - `Blynk` (via Library Manager).
     - `WiFi` and `WiFiUdp` (included in the ESP32 core).

2. **Configure Blynk**:
   - Create a new project in the Blynk app.
   - Add a virtual button (V0) to the project.
   - Copy the authentication token from the project and paste it into the code (`BLYNK_AUTH_TOKEN`).

3. **Upload the Code to the ESP32**:
   - Replace the following variables in the code:
     - `ssid`: Your Wi-Fi network name.
     - `password`: Your Wi-Fi password.
     - `macAddress`: MAC address of the target device.
   - Compile and upload the code to the ESP32.

4. **Test**:
   - Open the Blynk app and press the button to send the Magic Packet.

![image](https://github.com/user-attachments/assets/b9167ea1-fd60-4235-9fe6-627d0bc60053)


---

## **Project Structure**
- **`sendMagicPacket()` Function**: Sends the Wake-on-LAN packet.
- **Blynk Integration**: Triggers the Magic Packet when the button on Blynk is pressed.
- **Wi-Fi and Blynk Connection**: The ESP32 connects to Wi-Fi and Blynk at startup.

---

## **Future Improvements**
1. Add support for multiple devices.
2. Implement MAC address configuration via the Blynk app.
3. Add visual feedback in Blynk (e.g., an LED indicating successful packet delivery).

---

## **Author**
- Cayo Cesar
