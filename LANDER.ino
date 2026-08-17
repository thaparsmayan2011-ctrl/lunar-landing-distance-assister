#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 6;
const int buzzerPin=5;
const int greenLedPin = 7;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup () {
    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("LUNAR LANDER");

    lcd.setCursor(0, 1);
    lcd.print("SYSTEM ONLINE");

    delay(1500);
    lcd.clear();
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    float distance = duration * 0.0343/2;

    String status;

     if (distance > 50) {
        status = "SAFE";
        digitalWrite(ledPin, LOW);
        digitalWrite(greenLedPin, HIGH);
        noTone(buzzerPin);
    }
    else if (distance>20) {
        status = "CAUTION";

        digitalWrite(greenLedPin, LOW);
        unsigned long cycle = millis() % 1000;
        
        if (cycle < 150) {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 700);
        } else {
            digitalWrite(ledPin, LOW);
            noTone(buzzerPin);
        }
    }
    else if (distance>5) {
        status = "DANGER";
        digitalWrite(greenLedPin, LOW);
        unsigned long cycle = millis() % 300;

        if (cycle < 150) {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 1000);
        } else {
            digitalWrite(ledPin, LOW);
            noTone(buzzerPin);
        }
    }
    else {
        status = "TOUCHDOWN";
        digitalWrite(greenLedPin, LOW);
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 1800);
    }


    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | ");
    Serial.println(status);


    lcd.setCursor(0, 0);
    lcd.print("DIST: ");
    lcd.print(distance, 1);
    lcd.print(" cm   ");

    lcd.setCursor(0, 1);
    lcd.print(status);
    lcd.print("        ");

    delay(50);
}