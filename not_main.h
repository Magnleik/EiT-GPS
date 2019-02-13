
/*
 * Create an nbiot instance using default settings, which is the Telenor NB-IoT
 * Development Platform's APN (mda.ee) and 0 for both mobile country code and
 * mobile operator code (auto mode).
 * 
 * It's also possible to specify a different APN, mobile country code and
 * mobile network code. This should speed up attaching to the network.
 * 
 * Example:
 * TelenorNBIoT nbiot("mda.ee", 242, 01); // Telenor Norway
 * 
 * See list of codes here: https://www.mcc-mnc.com/
 */
#pragma once
#include <Udp.h>
#include <TelenorNBIoT.h>
#include <SoftwareSerial.h>
#ifdef SERIAL_PORT_HARDWARE_OPEN
#define ublox SERIAL_PORT_HARDWARE_OPEN
#else
SoftwareSerial ublox(10, 11);
#endif


TelenorNBIoT nbiot;

IPAddress remoteIP(172, 16, 15, 14);
int REMOTE_PORT = 1234;

unsigned long INTERVAL_MS = (unsigned long) 10 * 1000;
bool Connected = 0;
uint8_t buffSize = 20; 
char buff[20];



bool sendStringData(IPAddress ip, const uint16_t port, String str  );
bool sendByteData(IPAddress ip, const uint16_t port, String str, const char *data, const uint16_t length  );
void registeringOnNetwork();
size_t receiveData(char * buffer, uint16_t length);

