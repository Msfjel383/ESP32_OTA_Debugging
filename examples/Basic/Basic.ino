#include "OTAdebug.h"

// WiFi credentials
const char *hostName = "My_Device";
const char *ssid = "my_ssid";
const char *password = "my_password";

void setup() {
  debugSettings(3, 1, 115200, 1, 1);
  setupDebug();
  setupOTA(hostName, ssid, password);

    // Your setup code

}

void loop() {
  
  // Your loop code
  debuglnTest("use me to print debugging messages");
  debuglnInfo("use me to print system Infos");
  debuglnError("use me to print error messages");
  delay(1000);
  
	#if !defined(ESP32_RTOS) || !defined(ESP32)
    // If you do not use FreeRTOS, you have to regularly call the handle method.
    ArduinoOTA.handle();
  #endif

}