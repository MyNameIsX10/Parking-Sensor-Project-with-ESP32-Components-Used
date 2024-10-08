# Parking Sensor Project with ESP32

## Components Used

- **ESP32:** A microcontroller that manages the ultrasonic sensor, LEDs, and buzzer.
- **HC-SR04 Ultrasonic Sensor:** Measures the distance to an obstacle.
- **Buzzer:** Emits warning sounds as the distance to the obstacle decreases.
- **6 LEDs:** Two green, two yellow, and two red LEDs that indicate parking distance.
  - **Green LEDs:** The object is at a safe distance.
  - **Yellow LEDs:** Warning, the object is closer.
  - **Red LEDs:** Danger, the object is very close.
- **Graphical Interface in Processing:** Displays a stylized parking sensor using 6 semicircles to represent different distance intervals.

## Functionality

- **Distance Measurement:** The ultrasonic sensor measures the distance between the sensor and the obstacle.
  - **Distance intervals:**
    - **60 cm:** The first green LED turns on.
    - **50 cm:** Both green LEDs turn on.
    - **40 cm:** The first yellow LED turns on.
    - **30 cm:** Both yellow LEDs turn on.
    - **< 10 cm:** All red LEDs turn on.

- **Sound Indication:** The buzzer emits beeps with increasing frequency as the distance to the object decreases, helping to alert the user.

- **Graphical Interface in Processing:**
  - A stylized graphical interface of a parking sensor has been created, using 6 semicircles, each corresponding to a distance interval. The semicircles change color depending on the distance measured by the ultrasonic sensor:
    - **Green** for safe distances (> 60 cm),
    - **Yellow** for moderate distances (20-40 cm),
    - **Red** for dangerous distances (< 20 cm).

- **ESP32 to Processing Communication:** The graphical interface and ESP32 communicate via serial port. The ESP32 sends distance data to Processing, which updates the graphical visualization in real time.

## Source Code

- **ESP32 Firmware:** The ESP32 code handles distance measurement using the ultrasonic sensor, controlling the LEDs and activating the buzzer based on the detected distance. Distance data is sent to the PC via serial for processing by the Processing application.
- **Processing Application:** The Processing code interprets the data received from the ESP32 and updates the graphical interface, providing real-time visual feedback on the distance to the obstacle.
