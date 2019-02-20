#include "Nbiot.h"



void nbiotInit(){
  IotSerial.begin(9600);
  Serial.println("Connecting to NB-IoT module... ");
  while (!nbiot.begin(IotSerial)){
    Serial.println("Unable to connect to Nbiot, Trying again in 3. ");
    delay(3000);
  }
  while (!nbiot.createSocket()){
    Serial.print("Error creating socket. Error code: ");
    Serial.println(nbiot.errorCode(),DEC);
    delay(100);
  }
  registeringOnNetwork();
  Serial.println("Nbiot setup finished. ");
}







bool sendStringData( String str  ){
  return nbiot.sendString(remoteIP, REMOTE_PORT, str);
}

bool sendByteData(  const char *data, const uint16_t length  ){
  return nbiot.sendBytes(remoteIP, REMOTE_PORT, data,length);
}



void registeringOnNetwork(){
    while (nbiot.registrationStatus() != 2){
      nbiot.online();
      Serial.print("Connecting: ");
      Serial.println(nbiot.registrationStatus());
      Serial.println(nbiot.rssi());
      delay(5000);
           
    }

}



void transmitData(){
  if ((getGPSMinutes() == localMin)&&(getGPSFix())) {
    localMin = getGPSMinutes()+1;
    if(localMin == 60){
      localMin = 0; 
    }

    Serial.print("GPS time: ");
    Serial.print(getGPSMinutes());
    Serial.print(":");
    Serial.print(getGPSSeconds());


    char latitude[8];
    char longitude[8];
    dtostrf(getGPSLatitude(), 8, 4, latitude);
    dtostrf(getGPSLongitude(), 8, 4, longitude);
    IotSerial.listen();
    delay(1000);
    Serial.println("Sending data: ");
    Serial.println(sendByteData( latitude, 8));
    Serial.println(sendByteData( longitude, 8));
    GpsSerial.listen();
  }  
}



//size_t receiveData(char * buffer, uint16_t length){
//  size_t received = nbiot.receiveBytes(buffer, length);
//  size_t bytesRemaining = nbiot.receivedBytesRemaining();
//  if (received == 0){
//    Serial.println("No data received");
//    return received;
//
//   
//  }
//  if(bytesRemaining>0){
//    Serial.print ("Missing ");
//    Serial.print(bytesRemaining);
//    Serial.println("bytes.");
//  }
//  else{
//    Serial.print("Successfully received ");
//    Serial.print(received);
//    Serial.println(" bytes of data");
//  }
//  return received;
//}
  /* Only neede for online setup
  Serial.print("IMSI: ");
  Serial.println(nbiot.imsi());
  Serial.print("IMEI: ");
  Serial.println(nbiot.imei());
  */
