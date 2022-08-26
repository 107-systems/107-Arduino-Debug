/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Debug/graphs/contributors.
 */

#ifndef ARDUINO_DEBUG_HPP_
#define ARDUINO_DEBUG_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino.h>

#include <stdarg.h>
#include <stdlib.h>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#ifdef DBG_ENABLE_ERROR
#  define DBG_ERROR(fmt, ...) Debug.print(DebugLevel::Error, fmt, ## __VA_ARGS__)
#else
#  define DBG_ERROR(fmt, ...)
#endif

#ifdef DBG_ENABLE_WARNING
#  define DBG_WARNING(fmt, ...) Debug.print(DebugLevel::Warning, fmt, ## __VA_ARGS__)
#else
#  define DBG_WARNING(fmt, ...)
#endif

#ifdef DBG_ENABLE_INFO
#  define DBG_INFO(fmt, ...) Debug.print(DebugLevel::Info, fmt, ## __VA_ARGS__)
#else
#  define DBG_INFO(fmt, ...)
#endif

#ifdef DBG_ENABLE_DEBUG
#  define DBG_DEBUG(fmt, ...) Debug.print(DebugLevel::Debug, fmt, ## __VA_ARGS__)
#else
#  define DBG_DEBUG(fmt, ...)
#endif

#ifdef DBG_ENABLE_VERBOSE
#  define DBG_VERBOSE(fmt, ...) Debug.print(DebugLevel::Verbose, fmt, ## __VA_ARGS__)
#else
#  define DBG_VERBOSE(fmt, ...)
#endif

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class DebugLevel
{
  Error, Warning, Info, Debug, Verbose
};

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<size_t N>
class ArduinoDebug
{

public:

  ArduinoDebug(Stream & stream) : _stream{stream} { }

  void print(DebugLevel const lvl, char * fmt, ...)
  {
    print(lvl);

    va_list args;
    va_start(args, fmt);
    print(fmt, args);
    va_end(args);

    print("\r\n");
  }

private:

  Stream & _stream;

  void print(char const * fmt, va_list args)
  {
    char buf[N] = {0};
    vsnprintf(buf, N, fmt, args);
    print(buf);
  }

  void print(DebugLevel const lvl)
  {
    switch(lvl)
    {
    case DebugLevel::Error:   print("[E] "); break;
    case DebugLevel::Warning: print("[W] "); break;
    case DebugLevel::Info:    print("[I] "); break;
    case DebugLevel::Debug:   print("[D] "); break;
    case DebugLevel::Verbose: print("[V] "); break;
    }
  }

  void print(char const * msg)
  {
    for (size_t i = 0; i < std::min(N, strlen(msg)); i++)
      _stream.write(static_cast<uint8_t>(msg[i]));
  }
};

/**************************************************************************************
 * MACRO MAGIC
 **************************************************************************************/

#define DEBUG_INSTANCE(BUF_SIZE,OUT_STREAM) \
  static ArduinoDebug<BUF_SIZE> Debug(OUT_STREAM)

#endif /* ARDUINO_DEBUG_HPP_ */
