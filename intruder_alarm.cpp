#include <SoftwareSerial.h>

// Pins
const int pirPin = 2;          // PIR sensor pin
const int soundSensorPin = 3;  // Digital sound sensor pin
const int ledPin = 13;         // LED pin
const int buzzerPin = 12;      // Buzzer pin

// GSM module pins
const int rxPin = 8;           // RX pin for GSM module
const int txPin = 7;           // TX pin for GSM module

// Threshold values (adjustable)
const int soundThreshold = HIGH; // Digital sound sensor outputs HIGH when sound is detected

// Create software serial port for GSM communication
SoftwareSerial gsm(rxPin, txPin);

void setup() {
    // Initialize pins
    pinMode(pirPin, INPUT);
    pinMode(soundSensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    
    // Initialize serial communication
    Serial.begin(9600);
    gsm.begin(9600);
    
    // Configure the GSM module for SMS mode
    sendGSMCommand("AT");
    delay(1000);
    sendGSMCommand("AT+CMGF=1"); // Set SMS mode to text
    delay(1000);
    
    Serial.println("System Initialized. Waiting for intruder detection...");
}

void loop() {
    // Read sensor values
    int motionValue = digitalRead(pirPin);
    int soundValue = digitalRead(soundSensorPin);
    
    // Check if any sensor detects an intrusion
    if (soundValue == HIGH || motionValue == HIGH) {
        // Trigger the alarm: Turn on LED and buzzer
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
        
        // Send an SMS alert
        sendSMS("Intruder detected! Please check your premises.");
        
        // Wait for a while before resetting
        delay(5000);
        
        // Turn off LED and buzzer
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
    }

    // Small delay for sensor stabilization
    delay(200);
}

// Function to send SMS using the GSM module
void sendSMS(const char* message) {
    gsm.println("AT+CMGS=\"+91xxxxxxxxxx\""); // Replace with your phone number
    delay(1000);
    gsm.println(message);
    delay(1000);
    gsm.write(26); // ASCII code for Ctrl+Z to send SMS
    delay(5000);
}

// Function to send basic AT commands to GSM module
void sendGSMCommand(const char* command) {
    gsm.println(command);
    delay(1000);
}
