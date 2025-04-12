# ArduinoLogger

A simple Arduino logging library that supports structured logging with log levels: `DEBUG`, `INFO`, `WARNING`, and `ERROR`. Output is sent to `Serial` or any other `Stream` interface.

## Features

- clean log levels for embedded debugging
- works with `Serial`, `SoftwareSerial`, or any `Stream`
- configurable log level threshold
- minimal footprint for low-memory environments

## Installation

You can install this library by downloading it as a ZIP and importing into the Arduino IDE via:

**Sketch > Include Library > Add .ZIP Library...**

Or clone it into your libraries folder:

```bash
git clone https://github.com/banthaherder/ArduinoLogger.git
```

## Usage

```c++
#include <ArduinoLogger.h>

ArduinoLogger logger;

void setup() {
    Serial.begin(9600);

    logger.setLogLevel(LOG_LEVEL_DEBUG); // set minimum log level to show

    logger.debug("debug message");
    logger.info("system initialized");
    logger.warning("voltage low");
    logger.error("sensor failure");
}

void loop() {
    // your code
}
```

You can override the default log buffer size (128 bytes) before including the library:

```c++
#define LOGGER_BUFFER_SIZE 256  // increase buffer for longer messages

#include <ArduinoLogger.h>
```

📌 This must appear before any #include <ArduinoLogger.h> in your sketch or libraries.

## License
This project is licensed under the MIT License - see the LICENSE.md file for details
[MIT](https://choosealicense.com/licenses/mit/)
