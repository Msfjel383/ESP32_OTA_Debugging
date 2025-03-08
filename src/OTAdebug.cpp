#include "OTAdebug.h"

uint8_t g_Debuglevel = 3; 
bool g_Serial = true; 
uint16_t g_baudRate = 115200;
bool g_OTA = true;
bool g_Telnet = true;

void debugSettings(uint8_t Debuglevel, bool set_Serial, uint16_t baudRate, bool set_OTA, bool set_Telnet){
  otaSettings(set_OTA, set_Telnet);
  g_Debuglevel = Debuglevel;
  g_Serial = set_Serial;
  g_baudRate = baudRate;
  g_OTA = set_OTA;
  g_Telnet = set_Telnet;
}
void setupDebug() {
  if(Serial){
    if (g_Debuglevel > 0){
      Serial.begin(g_baudRate);
    }
  }
}

void ausgabeError(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Error: %s", input.c_str());
    if(g_Serial){
      Serial.println(buf);
    }
    if (g_OTA && g_Telnet){
      TelnetStream.println(buf);
    } 
}

void ausgabeInfo(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Info: %s", input.c_str());
    if(g_Serial){
      Serial.println(buf);
    }
    if (g_OTA && g_Telnet){
      TelnetStream.println(buf);
    } 
}

void ausgabeTest(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Test: %s", input.c_str());
    if(g_Serial){
      Serial.println(buf);
    }
    if (g_OTA && g_Telnet){
      TelnetStream.println(buf);
    }  
}