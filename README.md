# water level pump - Arduino Uno Module with Arduino IDE/Wokwi Simulator

## Descriptions

This project is an IoT-based smart pump system designed using Arduino Uno.
The system uses proximity sensors, relays, displays, potentiometers, and pumps to automate and monitor the fluid control process.
The system was developed in **Arduino IDE** and simulated using **Wokwi** before being deployed on actual hardware.

## Features

- **Distance Measurement**: Uses an ultrasonic sensor to measure the distance or water level.
- **Automatic Pump Control**: Activates the pump when specific distance thresholds are met.
- **Relay Control**: Controls the pump's power supply based on the sensor readings.
- **Real-Time Display**: Shows distance, pump status, or other relevant data on an LCD/LED display.
- **Adjustable Settings**: Uses a potentiometer to customize thresholds or other parameters.

## Technology Used

- **Hardware**:
  - Arduino Uno
  - Ultrasonic Sensor (e.g., HC-SR04)
  - Relay Module
  - LCD/LED Display
  - Potentiometer
  - Water Pump
  - Jumper Wires
- **Software**:
  - Arduino IDE
  - Wokwi Simulator (for virtual testing)

## Installations

1. Clone this repository to your local computer using the command:

   ```bash
   git clone https://github.com/username/repository-name.git
   
2. Open the project in Arduino IDE.

3. Ensure the required libraries are installed in Arduino IDE:
   - LiquidCrystal (for LCD display)
   - Servo (if servo motors are used)
   You can install these libraries via the Library Manager in Arduino IDE.

4. Load the .ino file into the Arduino IDE.

5. Connect the components as per the circuit diagram provided in the repository.

6. Simulate the circuit in Wokwi (optional) to ensure proper functionality.

7. Upload the code to the Arduino Uno board and test the system with real hardware.
