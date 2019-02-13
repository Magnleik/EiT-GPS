#include "not_main.h"




void setup() {
  Serial.begin(9600);
  while (!Serial);
  // Serial connection with Nbiot
  ublox.begin(9600);
  

  Serial.print("Connecting to NB-IoT module...\n");
  while (!nbiot.begin(ublox)) {
    Serial.println("Unable to connect to Nbiot");
    delay(1000);
  }

  // Try to create a listening socket at 1234
  while (!nbiot.createSocket()) {
    Serial.print("Error creating socket. Error code: ");
    Serial.println(nbiot.errorCode(), DEC);
    delay(100);
  }
}

void loop() {
  if (nbiot.isConnected()) {
    if (Connected!= 1){
      Connected = 1;
      Serial.println("Connected to network");
      Serial.println( sendStringData(remoteIP,REMOTE_PORT,"Hello, this is Arduino calling. I am waiting for data"));

    }
    receiveData(buff,buffSize);
    delay(INTERVAL_MS);


  } else {
    
    registeringOnNetwork();
  }
}


