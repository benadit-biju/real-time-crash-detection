# System Architecture

## Main Flow

```text
Accelerometer / Gyroscope
            |
            v
     ESP8266 / ESP32
            |
      Crash Analysis
            |
       +----+----+
       |         |
       v         v
      GPS      IoT Cloud
       |         |
       +----+----+
            |
            v
     Emergency Alert
            |
            v
     Monitoring UI
```

## Accident Detection

The controller monitors acceleration and motion data.

A possible accident is identified when sensor measurements exceed configured thresholds and additional validation conditions are satisfied.

The threshold values in the firmware are **prototype values** and must be calibrated using real sensor data.

## Location

A GPS module can provide latitude and longitude coordinates.

The location is attached to the emergency event and sent through the IoT/cloud layer.

## Alert

The cloud layer can forward the event to:

- Emergency contacts
- Monitoring dashboard
- Notification service
- Future GSM/LTE communication module

## Safety Note

This repository is an academic prototype. It is not a certified vehicle safety or emergency-response system. Real deployment requires extensive testing, validation, fail-safe design, and appropriate certification.
