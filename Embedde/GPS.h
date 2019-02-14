#pragma once
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

//SoftwareSerial ublox(rx,tx);
//Abit strange, but here tx = pin 8, rx = pin 9
SoftwareSerial GpsSerial(8, 9);
Adafruit_GPS GPS(&GpsSerial);
//   Connect the GPS TX (transmit) pin to Digital 8
//   Connect the GPS RX (receive) pin to Digital 9


// Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// Set to 'true' if you want to debug and listen to the raw GPS sentences
#define GPSECHO  true
uint32_t timer = millis();
void GPSInit();

void GPSDebug();
void printGPSData();
