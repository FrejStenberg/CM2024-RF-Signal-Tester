# Project Overview
A project developed as part of a project course at KTH Royal Institute of Technology, with a focus on medical technology. The device is intended to provide a simple visual indication of the received strength of RF signals, making it easier to identify locations or areas where signal strength may be insufficient.

The resulting signal-strength information could be used by healthcare professionals, medical technology personnel, or construction teams when planning, building, or renovating healthcare environments where reliable RF communication is important, such as with epilepsy alarms worn by patients.

## Function
The device scans for a selected RF network and measures its received signal strength (RSSI). The measured signal strength is then compared against predefined thresholds and translated into four levels: high, medium and low or no signal.

The current prototype uses the ESP32-C3's 2.4 GHz Wi-Fi functionality to perform these measurements. The signal level is conceptualized to be displayed via three LEDs or a display. The measurement is repeated at regular intervals, currently decided to be 2500 milliseconds, allowing the user to freely move between different locations and observe changes in signal strength.

The project was initially conceptualised as a test device for 869.2 MHz RF signals. The current 2.4 GHz Wi-Fi implementation therefore serves as a proof of concept for the signal measurement and display system. The primary reasons for this are that the 869.2 MHz frequency is heavily regulated by both duty-cycle and strength as well as that a significant amount of RF communication in medical equipment occurs at 2.4 GHz, making it the next best frequency to measure on. 

## Hardware & Components 
()

## Software Setup & Code
()

## Advantages and Limitations
()

