#include "OTA.h"

#ifndef OTA
void setupOTA(const char* nameprefix, const char* ssid, const char* password){};
#endif

#ifdef OTA

// Setup OTA Function
void setupOTA(const char* nameprefix, const char* ssid, const char* password) {
  // Configure the hostname
  uint16_t maxlen = strlen(nameprefix) + 7;
  char* fullhostname = new char[maxlen];
  uint8_t mac[6];
  WiFi.macAddress(mac);
  snprintf(fullhostname, maxlen, "%s-%02x%02x%02x", nameprefix, mac[3], mac[4], mac[5]);
  ArduinoOTA.setHostname(fullhostname);
  delete[] fullhostname;

  // Configure and start the WiFi station
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    debuglnError("Connection Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }

  // Optional configurations
  // ArduinoOTA.setPort(3232); // Uncomment for a custom port
   ArduinoOTA.setPassword("papiadmin"); // Uncomment to set password

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else
      type = "filesystem";

    debuglnInfo("Start updating " + type);
  });

  ArduinoOTA.onEnd([]() {
    debuglnInfo("\nEnd");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    char progressStr[50];
    snprintf(progressStr, sizeof(progressStr), "Progress: %u%%\r", (progress / (total / 100)));
    debuglnInfo(progressStr);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    if (error == OTA_AUTH_ERROR){
       debuglnError("\nAuth Failed");
    }
    else if (error == OTA_BEGIN_ERROR){
       debuglnError("\nBegin Failed");
    }
    else if (error == OTA_CONNECT_ERROR){
      debuglnError("\nConnect Failed");
    }
    else if (error == OTA_RECEIVE_ERROR){
      debuglnError("\nReceive Failed");
    }
    else if (error == OTA_END_ERROR){
      debuglnError("\nEnd Failed");
    }
  });

  ArduinoOTA.begin();
  #ifdef TELNET
  TelnetStream.begin();
  #endif

  debuglnInfo("OTA Initialized");
  debuglnInfo("IP address: " + WiFi.localIP().toString());
}
#endif