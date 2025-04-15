#include <ArduinoLogger.h>

ArduinoLogger logger;

void setup() {
  Serial.begin(9600);

  logger.setLogLevel(LOG_LEVEL_DEBUG); // change this to INFO, WARN, etc.

  int sensorA = 42;
  int sensorB = 7;
  logger.debugf("raw readings: sensorA=%d, sensorB=%d\r\n", sensorA, sensorB);
  logger.infof("processed: sensorA=%d, sensorB=%d\r\n", sensorA + 10,
               sensorB + 5);
  logger.warnf("threshold approaching: A=%d, B=%d\r\n", sensorA, sensorB);
  logger.errorf("sensor fault detected: A=%d\r\n", sensorA);
}

void loop() {
  // do nothing
}
