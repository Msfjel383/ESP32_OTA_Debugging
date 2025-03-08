//
// Forked from https://github.com/SensorsIot/ESP32-OTA
// Print statements mit debug statments ersetzt
//

#ifndef OTA_H
#define OTA_H

#include "settings.h"
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <TelnetStream.h>
#include "OTAdebug.h"

// Function prototypes
void setupOTA(const char* nameprefix, const char* ssid, const char* password);

#endif // OTA_H
