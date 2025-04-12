#include <ArduinoLogger.h>

ArduinoLogger logger;

void setup() {
    Serial.begin(9600);
    while (!Serial); // wait for serial

    
    logger.setLogLevel(LOG_LEVEL_DEBUG);

    logger.debug("debugging...");
    logger.info("system initialized");
    logger.warning("temperature rising");
    logger.error("sensor failure");
}

void loop() {
    // main loop code
 }
