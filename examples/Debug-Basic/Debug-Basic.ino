/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Debug/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#define DBG_ENABLE_ERROR
#define DBG_ENABLE_WARNING
#define DBG_ENABLE_INFO
#define DBG_ENABLE_DEBUG
#define DBG_ENABLE_VERBOSE
#include <ArduinoDebug.hpp>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

DEBUG_INSTANCE(80, Serial);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

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

void loop()
{
  
}
