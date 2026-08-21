# Wiring Guide

## MPU6050

Typical I2C connection:

| MPU6050 | ESP8266 NodeMCU |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCL | D1 / GPIO5 |
| SDA | D2 / GPIO4 |

## GPS Module

A GPS module such as NEO-6M can be connected using a suitable serial interface.

Check the exact module voltage and UART requirements before connecting it.

## SOS Button

| Button | NodeMCU |
|---|---|
| One side | D6 / GPIO12 |
| Other side | GND |

The firmware uses `INPUT_PULLUP`.

## Optional Components

- Buzzer
- Status LED
- GSM/LTE module
- OLED display
- Additional gyroscope
- Vehicle power monitoring
