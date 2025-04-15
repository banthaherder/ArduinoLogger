#include "ArduinoLogger.h"

ArduinoLogger::ArduinoLogger(Stream &stream, LogLevel level)
    : _stream(stream), _level(level) {}

void ArduinoLogger::setLogLevel(LogLevel level) {
    _level = level;
}

void ArduinoLogger::debug(const char *msg) {
    _log(LOG_LEVEL_DEBUG, "[DEBUG] -", msg);
}

void ArduinoLogger::info(const char *msg) {
    _log(LOG_LEVEL_INFO, "[INFO] -", msg);
}

void ArduinoLogger::warn(const char *msg) {
    _log(LOG_LEVEL_WARN, "[WARN] -", msg);
}

void ArduinoLogger::error(const char *msg) {
    _log(LOG_LEVEL_ERROR, "[ERROR] -", msg);
}

void ArduinoLogger::debugf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    _logf(LOG_LEVEL_DEBUG, "[DEBUG] -", format, args);
    va_end(args);
}

void ArduinoLogger::infof(const char *format, ...) {
    va_list args;
    va_start(args, format);
    _logf(LOG_LEVEL_INFO, "[INFO] -", format, args);
    va_end(args);
}

void ArduinoLogger::warnf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    _logf(LOG_LEVEL_WARN, "[WARN] -", format, args);
    va_end(args);
}

void ArduinoLogger::errorf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    _logf(LOG_LEVEL_ERROR, "[ERROR] -", format, args);
    va_end(args);
}

void ArduinoLogger::_log(LogLevel msgLevel, const char *prefix, const char *msg) {
    if (msgLevel >= _level) {
        _stream.print(prefix);
        _stream.print(" ");
        _stream.println(msg);
    }
}

void ArduinoLogger::_logf(LogLevel msgLevel, const char *prefix, const char *format, va_list args) {
    if (msgLevel < _level) return;

    char buffer[LOGGER_BUFFER_SIZE];
    int len = vsnprintf(buffer, sizeof(buffer), format, args);

    _stream.print(prefix);
    _stream.print(" ");
    _stream.print(buffer);

    if (len >= (int)sizeof(buffer)) {
        _stream.println("[WARN] - log message truncated");
    }
}
