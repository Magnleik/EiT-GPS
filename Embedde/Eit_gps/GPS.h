#pragma once
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial GpsSerial(8, 9);
Adafruit_GPS GPS(&GpsSerial);
#define GPSECHO true

int localMin;
uint32_t timer = millis();

void GPSInit();
void GPSFixReady();
void GPSParse();
void GPSDebug();
void printGPSData();


int getGPSSeconds();
int getGPSMinutes();
float getGPSLatitude();
float getGPSLongitude();
