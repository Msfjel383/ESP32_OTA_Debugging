//
// Forked from https://github.com/SensorsIot/ESP32-OTA
// Print statements mit debug statments ersetzt
//

#ifndef OTA_H
#define OTA_H

#ifdef ESP32
#include <WiFi.h>
#include <ESPmDNS.h>
#else
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#endif

#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <TelnetStream.h>
#include "OTAdebug.h"

// Function prototypes
void otaSettings (bool set_OTA, bool set_Telnet);
void setupOTA (const char* nameprefix, const char* ssid, const char* password);
void ota_handle (void * parameter);

extern bool o_OTA;
extern bool o_Telnet;

#endif // OTA_H
