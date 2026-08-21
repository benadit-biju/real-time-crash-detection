/*
 * IoT Accident Detection System
 * ESP8266/ESP32 prototype firmware
 *
 * Prototype functions:
 * - Motion/impact monitoring
 * - Manual SOS button
 * - Crash detection logic
 * - GPS/IoT integration points
 */

#include <Wire.h>

// -----------------------------
// Pin Configuration
// -----------------------------

#define SOS_BUTTON_PIN D6
#define STATUS_LED LED_BUILTIN

// -----------------------------
// Detection Configuration
// -----------------------------

const float IMPACT_THRESHOLD = 2.5;
const unsigned long CONFIRMATION_WINDOW_MS = 1500;
const unsigned long ALERT_COOLDOWN_MS = 30000;

unsigned long possibleCrashTime = 0;
unsigned long lastAlertTime = 0;

bool crashCandidate = false;


// -----------------------------
// Sensor Initialization
// -----------------------------

void initializeSensors() {
    Wire.begin();

    /*
     * Initialize MPU6050 or another
     * accelerometer/gyroscope here.
     *
     * Example:
     * - Read acceleration on X/Y/Z
     * - Calculate resultant acceleration
     * - Detect sudden changes
     */
}


// -----------------------------
// Read Acceleration
// -----------------------------

float readAccelerationMagnitude() {

    /*
     * Replace this demo value with
     * actual MPU6050 sensor data.
     */

    float ax = 0.0;
    float ay = 0.0;
    float az = 1.0;

    return sqrt(
        ax * ax +
        ay * ay +
        az * az
    );
}


// -----------------------------
// Get GPS Location
// -----------------------------

String getGPSLocation() {

    /*
     * Integrate a GPS module such as
     * NEO-6M using TinyGPS++ or another
     * GPS parsing library.
     */

    return "GPS_NOT_CONFIGURED";
}


// -----------------------------
// Send Emergency Alert
// -----------------------------

void sendEmergencyAlert() {

    if (millis() - lastAlertTime < ALERT_COOLDOWN_MS) {
        return;
    }

    String location = getGPSLocation();

    Serial.println("================================");
    Serial.println("EMERGENCY ALERT");
    Serial.println("Possible accident detected.");
    Serial.print("Location: ");
    Serial.println(location);
    Serial.println("================================");

    /*
     * Add cloud communication here.
     *
     * Possible options:
     * - Firebase
     * - MQTT
     * - HTTP REST API
     * - GSM/LTE module
     */

    digitalWrite(STATUS_LED, LOW);
    delay(1000);
    digitalWrite(STATUS_LED, HIGH);

    lastAlertTime = millis();
}


// -----------------------------
// Crash Detection
// -----------------------------

void checkForAccident() {

    float acceleration =
        readAccelerationMagnitude();

    Serial.print("Acceleration: ");
    Serial.println(acceleration);

    if (acceleration >= IMPACT_THRESHOLD) {

        if (!crashCandidate) {
            crashCandidate = true;
            possibleCrashTime = millis();

            Serial.println(
                "Possible impact detected."
            );
        }
    }

    if (crashCandidate) {

        if (millis() - possibleCrashTime
            <= CONFIRMATION_WINDOW_MS) {

            // Additional validation can be
            // performed here.

        } else {

            crashCandidate = false;

            Serial.println(
                "Accident event confirmed."
            );

            sendEmergencyAlert();
        }
    }
}


// -----------------------------
// Setup
// -----------------------------

void setup() {

    Serial.begin(115200);

    pinMode(
        SOS_BUTTON_PIN,
        INPUT_PULLUP
    );

    pinMode(
        STATUS_LED,
        OUTPUT
    );

    digitalWrite(
        STATUS_LED,
        HIGH
    );

    initializeSensors();

    Serial.println(
        "IoT Accident Detection System Ready"
    );
}


// -----------------------------
// Main Loop
// -----------------------------

void loop() {

    // Manual emergency trigger.
    if (digitalRead(SOS_BUTTON_PIN) == LOW) {

        Serial.println(
            "Manual SOS activated."
        );

        sendEmergencyAlert();

        delay(1000);
    }

    // Automatic accident detection.
    checkForAccident();

    delay(100);
}
