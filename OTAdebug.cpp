#include "OTAdebug.h"
void setupDebug() {
    #ifdef SERIELL
        #if DEBUG > 0
            Serial.begin(BAUDRATE);
        #endif
    #endif
}

void ausgabeError(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Error: %s", input.c_str());
    #ifdef SERIELL
        Serial.println(buf);
    #endif
    #if defined(OTA) && defined(TELNET)
        TelnetStream.println(buf);
    #endif  
}

void ausgabeInfo(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Info: %s", input.c_str());
    #ifdef SERIELL
        Serial.println(buf);
    #endif
    #if defined(OTA) && defined(TELNET)
        TelnetStream.println(buf);
    #endif  
}

void ausgabeTest(String input) {
    char buf[100];
    snprintf(buf, sizeof(buf), "Test: %s", input.c_str());
    #ifdef SERIELL
        Serial.println(buf);
    #endif
    #if defined(OTA) && defined(TELNET)
        TelnetStream.println(buf);
    #endif  
}