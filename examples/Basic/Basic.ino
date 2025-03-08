#include <Arduino.h>
#include "settings.h"
#include "OTAdebug.h"

void setup() {
  setupDebug();
  setupOTA(hostName, ssid, password);

    // Your setup code

}

void loop() {
  
  // Your loop code

  ArduinoOTA.handle();
}