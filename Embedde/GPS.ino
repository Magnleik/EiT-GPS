#include "GPS.h"

void GPSInit(){
  GPS.begin(9600);
  delay(5000);
  Serial.println("Adafruit GPS init start. ");  
  //enable RMC(recommended minimum), and GGA(fix data) including altitude
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  
  //enable only RMC, not altitude
  //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
  
  //Update rate
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  
  //Antenna status updates
  GPS.sendCommand(PGCMD_ANTENNA); 

  delay(1000);

  //For debug, request firmvare version.
  GpsSerial.println(PMTK_Q_RELEASE);
  Serial.println("GPS init finised. ");
}

//Prints out raw gps information
void GPSDebug(){
  char c = GPS.read();
  if ((c) && (GPSECHO)){
    Serial.write(c);
  }
}

void printGPSData(){
   // if millis() or timer wraps around, we'll just reset it
  if (timer > millis())  timer = millis();

  // approximately every 2 seconds or so, print out the current stats
  if (millis() - timer > 2000) { 
    timer = millis(); // reset the timer
    
    Serial.print("\nTime: ");
    Serial.print(GPS.hour, DEC); Serial.print(':');
    Serial.print(GPS.minute, DEC); Serial.print(':');
    Serial.print(GPS.seconds, DEC); Serial.print('.');
    Serial.println(GPS.milliseconds);
    Serial.print("Date: ");
    Serial.print(GPS.day, DEC); Serial.print('/');
    Serial.print(GPS.month, DEC); Serial.print("/20");
    Serial.println(GPS.year, DEC);
    Serial.print("Fix: "); Serial.print((int)GPS.fix);
    Serial.print(" quality: "); Serial.println((int)GPS.fixquality); 
  }
}
