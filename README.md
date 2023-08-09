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
  <a href="https://github.com/107-systems/viper"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="40%"></a>
</p>

Arduino library for providing convenient macros for printf-style debugging.

This library works for
* [ArduinoCore-samd](https://github.com/arduino/ArduinoCore-samd): [`Arduino Zero`](https://store.arduino.cc/arduino-zero), [`MKR 1000`](https://store.arduino.cc/arduino-mkr1000-wifi), [`MKR WiFi 1010`](https://store.arduino.cc/arduino-mkr-wifi-1010), [`Nano 33 IoT`](https://store.arduino.cc/arduino-nano-33-iot), [`MKR GSM 1400`](https://store.arduino.cc/arduino-mkr-gsm-1400-1415), [`MKR NB 1500`](https://store.arduino.cc/arduino-mkr-nb-1500-1413), [`MKR WAN 1300/1310`](https://store.arduino.cc/mkr-wan-1310) :heavy_check_mark:
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble), [`Nano RP2040 Connect`](https://store.arduino.cc/nano-rp2040-connect), [`Edge Control`](https://store.arduino.cc/edge-control) :heavy_check_mark:
* [arduino-esp32](https://github.com/espressif/arduino-esp32): `ESP32 Dev Module`, `ESP32 Wrover Module`, ... :heavy_check_mark:
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:
* [ArduinoCore-renesas](https://github.com/arduino/ArduinoCore-renesas): [`Portenta C33`](https://store.arduino.cc/products/portenta-c33), [`Uno R4 WiFi`](https://store.arduino.cc/products/uno-r4-wifi), [`Uno R4 Minima`](https://store.arduino.cc/products/uno-r4-minima), ... :heavy_check_mark:

## Example
```C++
#define DBG_ENABLE_ERROR
#define DBG_ENABLE_WARNING
#define DBG_ENABLE_INFO
#define DBG_ENABLE_DEBUG
#define DBG_ENABLE_VERBOSE
#include <107-Arduino-Debug.hpp>
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
**Note**: If you enable pretty printing using 4-bit shell color escape sequences via `prettyPrintOn` then you'll need to start `minicom` with `--color=on`:
```bash
minicom -D /dev/ttyACM0 --color=on
```
