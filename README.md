**Lunar Landing Distance Assister**

An Arduino-based distance warning system inspired by a lunar landing assistant.

The project uses an HC-SR04 ultrasonic sensor to measure distance from a surface and gives different warnings depending on how close the object is.

**Features**

- LCD displays distance and landing status
- Green LED shows SAFE mode
- Red LED blinks during CAUTION and DANGER
- Buzzer gives different warning sounds
- Continuous warning during TOUCHDOWN

**Distance Zones**

- Above 50 cm: SAFE
- 20–50 cm: CAUTION
- 5–20 cm: DANGER
- 5 cm or less: TOUCHDOWN

**Components**
- Arduino Uno
- HC-SR04 ultrasonic sensor
- 16x2 I2C LCD
- 2 LEDs
- 2 × 220Ω resistors
- Buzzer
- Breadboard
- Jumper wires

**Procedure**
1. Connect the HC-SR04 ultrasonic sensor to the Arduino.
2. Connect the I2C LCD, green LED, red LED, and buzzer.
3. Upload the Arduino code to the board.
4. The ultrasonic sensor continuously measures the distance from an object.
5. The Arduino classifies the distance into four zones:
   - SAFE
   - CAUTION
   - DANGER
   - TOUCHDOWN
6. The LCD displays the current distance and status.
7. The LEDs and buzzer change their behavior depending on the distance.

**Connections**

**HC-SR04 Ultrasonic Sensor**
- VCC → 5V
- GND → GND
- TRIG → D9
- ECHO → D10

**I2C LCD**
- VCC → 5V
- GND → GND
- SDA → A4
- SCL → A5

**Green LED**
- Arduino D7 → 220Ω resistor → LED long leg (+)
- LED short leg (-) → GND

**Red Warning LED**
- Arduino D6 → 220Ω resistor → LED long leg (+)
- LED short leg (-) → GND

**Buzzer**
- Positive (+) → D5
- Negative (-) → GND

**Breadboard Power**
- Arduino 5V → positive power rail
- Arduino GND → ground rail


**How It Works**

The HC-SR04 sends an ultrasonic pulse and measures how long it takes for the
echo to return. The Arduino converts this time into distance and then compares it with
preset distance limits. Based on the result, it updates the LCD, LEDs, and buzzer.




