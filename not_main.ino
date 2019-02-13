#include "not_main.h"

bool sendStringData(IPAddress ip, const uint16_t port, String str  ){
  return nbiot.sendString(remoteIP, REMOTE_PORT, str);
}

bool sendByteData(IPAddress ip, const uint16_t port, String str, const char *data, const uint16_t length  ){
  return nbiot.sendBytes(remoteIP, REMOTE_PORT, data,length);
}


void registeringOnNetwork(){
    nbiot.online();
    Serial.print("Connecting: ");
    Serial.println(nbiot.registrationStatus());
    Serial.println(nbiot.rssi());
    delay(5000);  
}

size_t receiveData(char * buffer, uint16_t length){
  size_t received = nbiot.receiveBytes(buffer, length);
  size_t bytesRemaining = nbiot.receivedBytesRemaining();
  if (received == 0){
    Serial.println("No data received");
    return received;

   
  }
  if(bytesRemaining>0){
    Serial.print ("Missing ");
    Serial.print(bytesRemaining);
    Serial.println("bytes.");
  }
  else{
    Serial.print("Successfully received ");
    Serial.print(received);
    Serial.println(" bytes of data");
  }
  return received;
}
  /* Only neede for online setup
  Serial.print("IMSI: ");
  Serial.println(nbiot.imsi());
  Serial.print("IMEI: ");
  Serial.println(nbiot.imei());
  */
