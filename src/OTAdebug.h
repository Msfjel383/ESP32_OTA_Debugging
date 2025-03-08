//
// Created by MS on 23.11.2024.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h> // Für String
#include "OTA.h"

// Debug-Level:
// 0 = kein debug output
// 1 = Fehlermeldungen
// 2 = Infos + Fehlermeldungen
// 3 = Tests + Infos + Fehlermeldungen
void debugSettings(uint8_t Debuglevel, bool set_Serial, uint16_t baudRate, bool set_OTA, bool set_Telnet);
void setupDebug();
void ausgabeError(String input);
void ausgabeInfo(String input);
void ausgabeTest(String input);

extern uint8_t g_Debuglevel;
extern bool g_Serial;
extern uint16_t g_baudRate;
extern bool g_OTA;
extern bool g_Telnet;

#if DEBUG >= 1
    #define debuglnError(x) {String input = String(x); ausgabeError(input);}
#else
    #define debuglnError(x)
#endif

#if DEBUG >= 2
    #define debuglnInfo(x) {String input = String(x); ausgabeInfo(input);}
#else
    #define debuglnInfo(x)
#endif

#if DEBUG >= 3
    #define debuglnTest(x) {String input = String(x); ausgabeTest(input);}
#else
    #define debuglnTest(x)
#endif

#endif //DEBUG_H
