#pragma once
#include <Udp.h>
#include <TelenorNBIoT.h>
#include <SoftwareSerial.h>
#ifdef SERIAL_PORT_HARDWARE_OPEN
#define IotSerial SERIAL_PORT_HARDWARE_OPEN
#else
//SoftwareSerial ublox(rx,tx);
SoftwareSerial IotSerial(10, 11);
#endif


TelenorNBIoT nbiot;

IPAddress remoteIP(172, 16, 15, 14);
int REMOTE_PORT = 1234;

unsigned long INTERVAL_MS = (unsigned long) 60 * 1000;
bool Connected = 0;
uint8_t buffSize = 20; 
char buff[20];


void nbiotInit();
bool sendStringData(IPAddress ip, const uint16_t port, String str  );
bool sendByteData(IPAddress ip, const uint16_t port, String str, const char *data, const uint16_t length  );
void registeringOnNetwork();
size_t receiveData(char * buffer, uint16_t length);
