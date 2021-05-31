<a href="https://107-systems.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/107-systems.png" width="15%"></a>
`107-Arduino-Debug`
===================
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-Debug.svg?)](https://www.ardu-badge.com/107-Arduino-Debug)
[![Compile Examples](https://github.com/107-systems/107-Arduino-Debug/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-Debug/actions?workflow=Compile+Examples)
[![Check Arduino](https://github.com/107-systems/107-Arduino-Debug/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/107-systems/107-Arduino-Debug/actions/workflows/check-arduino.yml)
[![Check keywords.txt](https://github.com/107-systems/107-Arduino-Debug/actions/workflows/check-keywords-txt.yml/badge.svg)](https://github.com/107-systems/107-Arduino-Debug/actions/workflows/check-keywords-txt.yml)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-Debug/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Debug/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-Debug/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-Debug/actions?workflow=Spell+Check)

<p align="center">
  <a href="https://github.com/107-systems/Viper-Firmware"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="40%"></a>
</p>

Arduino library for providing convenient macros for printf-style debugging.

## Example
```C++
#define DBG_ENABLE_ERROR
#define DBG_ENABLE_WARNING
#define DBG_ENABLE_INFO
#define DBG_ENABLE_DEBUG
#define DBG_ENABLE_VERBOSE
#include <ArduinoDebug.hpp>
/* ... */
DEBUG_INSTANCE(80, Serial);
/* ... */
void setup()
{
  Serial.begin(9600);
  while (!Serial) { }

  DBG_ERROR  ("A serious error has occurred during operation X: %d", -42);
  DBG_WARNING("No connection to %s, retrying in %d seconds ...", "127.0.0.1", 5);
  DBG_INFO   ("Did you know you can also print octal values: %o", 0xCA);
  DBG_DEBUG  ("MCP2515 CANSTAT = 0x%02X", 0xFE);
  DBG_VERBOSE("You are probably aware that PI = %4.2f", PI);
}
/* ... */
```
