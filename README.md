# Project Overview
A project developed as part of a course at KTH Royal Institute of Technology, with a focus on medical technology. The device is intended to provide a simple visual indication of received RF signal strength, making it easier to identify locations where wireless coverage may be insufficient.

The resulting signal-strength information could be used by healthcare professionals, medical technology personnel, healthcare facility planners and construction teams when planning, building, or renovating healthcare environments where reliable wireless communication is important, such as for wrist-worn epilepsy alarms.

## Function
The device scans for a selected Wi-Fi network and measures its received signal strength indicator (RSSI). The measured signal strength is compared against predefined thresholds and classified into four levels: high, medium, low, and zero or no signal.

The current prototype uses the ESP32-C3's 2.4 GHz Wi-Fi functionality to perform these measurements. The signal level is displayed using three LEDs. Measurements are repeated at regular intervals, currently set to 1500 milliseconds between scans, allowing the user to move between different locations and observe changes in signal strength.

The project was initially conceptualised as a test device for RF signals at 869.2 MHz, specifically to assess the signal coverage of wrist-worn epilepsy alarms. The current 2.4 GHz Wi-Fi implementation serves as a proof of concept for the signal measurement, classification, and visual indication functions. This approach was chosen because implementing direct measurements at 869.2 MHz would require suitable radio hardware and consideration of the applicable frequency-allocation and transmission regulations. Additionally, 2.4 GHz Wi-Fi provides an accessible platform for developing and testing the prototype's core functionality.

The Wi-Fi implementation does not directly measure the signal strength or reliability of 869.2 MHz epilepsy alarms. Further hardware development and testing would be required to support that application.

## Signal Generator
A TP-Link TL-WR802N wireless router was selected as the Wi-Fi access point used to generate the test signal. The router is powered on and configured to broadcast a Wi-Fi network. The target network's SSID is stored in the prototype's source code as a constant character string, allowing the device to identify and measure the signal from the selected network.

## Software
The prototype was programmed in C++ using the Arduino IDE and the ESP32 Wi-Fi library. The software scans for a predefined Wi-Fi network at regular intervals, retrieves its received signal strength indicator (RSSI) in dBm, and classifies the measurement according to predefined thresholds. The corresponding signal level is displayed using three LEDs, while the RSSI value and detection status are printed to the serial monitor for debugging and testing. A reset button is also implemented to restart the device when needed.

## Hardware 
The prototype consists of an ESP32-C3 microcontroller, three LEDs (green, yellow, and red), and a reset button. A TP-Link TL-WR802N wireless router serves as the external Wi-Fi signal source during testing.

A new ESP32-C3 development board was used to construct the prototype. Pin headers were soldered to the board to provide reliable electrical connections between the microcontroller's pins and the external components. GPIO pins 2, 3, and 4 were used to control the green, yellow, and red LEDs, respectively. Each LED was connected in series with a current-limiting 220Ω resistor before being connected to ground. All components were mounted onto a small breadboard.

A custom 3D-printed case was designed and printed to hold the breadboard inside, containing a tray and a lid. The tray included a cable hole, while the lid included three openings to expose the LEDs.

## General
The RSSI thresholds used by the prototype to distinguish between signal levels have been set with the help of information of the National Health Service (NHS) in England as well as Cisco are defined as follows:
- High: −67 dBm or higher.
- Medium: Below −67 dBm and down to −75 dBm.
- Low: Below −75 dBm and down to −83 dBm.
- Zero / No signal: Below −83 dBm or when the target network is not detected.
The high signal level is indicated by the green LED, the medium level by the yellow LED, and both low and zero signal levels by the red LED. The two lowest classifications share the red LED because weak or undetected signals both indicate areas requiring further investigation and potential improvements to wireless coverage.

## Testing
To evaluate the prototype's output, the distance between the Wi-Fi router and the receiver was measured at the points where the LED classification changed from high to medium and from medium to low signal strength. Each transition was measured over seven trials without physical obstructions between the router and receiver. The corresponding distances were recorded to calculate the mean and range for each transition. The high-to-medium transition was measured at a mean distance of 10.3 metres, while the medium-to-low transition occurred at a mean distance of 23.0 metres. The results were used to assess the consistency of the prototype's signal-strength classification under the tested conditions.

## Getting Started
Requirements
- ESP32-C3 development board
- Arduino IDE
- ESP32 Wi-Fi library
- Three LEDs and suitable current-limiting resistors
- Breadboard and connecting wires
- A Wi-Fi router broadcasting the target network

Setup
- Install the Arduino IDE and configure ESP32 board support
- Connect the LEDs to GPIO pins 2, 3 and 4
- Open the source file in the src directory
- Change the target SSID in the code to match the Wi-Fi network being tested
- Select the appropriate ESP32-C3 board and port in the Arduino IDE
- Upload the program to the board
- Open the serial monitor to observe RSSI readings and network detection status
- Move the receiver to different locations and observe the LED indication

## License
This project was developed for educational purposes as part of the CM2024 Technology and Health Project Course at KTH Royal Institute of Technology.
No open-source license has been specified for this project. If you use, modify, or build upon this work, please acknowledge the original developers and include a link to this repository.
