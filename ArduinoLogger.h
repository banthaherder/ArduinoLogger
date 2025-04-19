#ifndef ARDUINO_LOGGER_H
#define ARDUINO_LOGGER_H

#ifndef LOGGER_BUFFER_SIZE
#define LOGGER_BUFFER_SIZE 128
#endif

#include <Arduino.h>

enum LogLevel { LOG_LEVEL_DEBUG, LOG_LEVEL_INFO, LOG_LEVEL_WARN, LOG_LEVEL_ERROR, LOG_LEVEL_NONE };

class ArduinoLogger {
public:
  ArduinoLogger(Stream &stream = Serial, LogLevel level = LOG_LEVEL_INFO);

  void setLogLevel(LogLevel level);

  void debug(const char *msg);
  void info(const char *msg);
  void warn(const char *msg);
  void error(const char *msg);

  void debugf(const char *format, ...);
  void infof(const char *format, ...);
  void warnf(const char *format, ...);
  void errorf(const char *format, ...);

private:
  Stream &_stream;
  LogLevel _level;

  void _log(LogLevel msgLevel, const char *prefix, const char *msg);
  void _logf(LogLevel msgLevel, const char *prefix, const char *format, va_list args);
};

#endif
