#include "Nbiot.h"
#include "GPS.h"


//float a = 63.4199132; 
//float b = 10.4149189;


void setup() {
  Serial.begin(9600);
  nbiotInit();
  GPSInit();
  Serial.println("Setup finished. ");
}



void loop() {
  //if (nbiot.isConnected()) {
 //  if (Connected!= 1){
  //    Connected = 1;
   //   Serial.println("Connected to network");
   // }
    //receiveData(buff,buffSize);
    //Serial.print("Data sendt: ");
    //Serial.println( sendStringData(remoteIP,REMOTE_PORT,"Hello, this is Arduino calling."));
    //delay(INTERVAL_MS);
  //} 
  GPSDebug();
  printGPSData();
}
