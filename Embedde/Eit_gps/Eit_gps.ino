#include "GPS.h"
#include "Nbiot.h"


void setup()  
{
  Serial.begin(9600);
  delay(5000);
  nbiotInit();
  GPSInit(); 
  //Listeningchannels GpsSerial and IotSerial. Default start is GPSSerial. 
}

void loop()                     // run over and over again
{
  GPSParse();
  GPSDebug();
  //printGPSData();
  transmitData();
  if (!getGPSFix()){
    GPSFixReady();
  }
  if (millis()%1000 == 0){
    Serial.print("GPS minutes: ");
    Serial.println(getGPSMinutes());
    Serial.print("Local minut: ");
    Serial.println(localMin);
    Serial.print("GPS FIX    : ");
    Serial.println(getGPSFix());
  }
}
