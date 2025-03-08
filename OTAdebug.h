//
// Created by MS on 23.11.2024.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h> // Für String
#include "settings.h"
#include "OTA.h"

// Debug-Level:
// 0 = kein debug output
// 1 = Fehlermeldungen
// 2 = Infos + Fehlermeldungen
// 3 = Tests + Infos + Fehlermeldungen
void setupDebug();
void ausgabeError(String input);
void ausgabeInfo(String input);
void ausgabeTest(String input);

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
