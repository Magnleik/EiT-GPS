#include "GPS.h"
#include "Nbiot.h"
#include <stdio.h>

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
  //if (millis()%5000 == 0){
  //  Serial.print("GPS minutes: ");
  //  Serial.println(getGPSMinutes());
  //  Serial.print("Local minut: ");
  //  Serial.println(localMin);
  //  Serial.print("GPS FIX    : ");
  //  Serial.println(getGPSFix());
  //}
}


    //Serial.print("GPS time: ");
    //Serial.print(getGPSMinutes());
    //Serial.print(":");
    //Serial.print(getGPSSeconds());
    //float lat = 6339.12345;
    //float lon = 1023.21231;
    //char latitude[9];
    //char longitude[9];
    //dtostrf(lat, 8, 3, latitude);
    //dtostrf(lon, 8, 3, longitude);
    //char buff [18];
    //for(int i = 0; i<17; i++ ){
    //  if (i<8){
    //      buff[i] = latitude[i];
    //  }
    //  else if(i==8){
    //      buff[i] = ' ';
    //  }
    //  else{
    //      buff[i] = longitude[i%9  ];
    //  }
    //}
    //buff[17] = '\0';
    ////IotSerial.listen();
    //delay(10000);
    //Serial.println("Sending data: ");
    //Serial.println(sendByteData( buff, 17));  
