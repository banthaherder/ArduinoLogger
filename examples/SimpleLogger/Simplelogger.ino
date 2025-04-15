#include <ArduinoLogger.h>

ArduinoLogger logger;

void setup() {
  Serial.begin(9600);

  logger.setLogLevel(LOG_LEVEL_DEBUG); // change this to INFO, WARN, etc.

  logger.debug("debugging...");
  logger.info("system initialized");
  logger.warn("temperature rising");
  logger.error("sensor failure");
}

void loop() {
  // do nothing
}
