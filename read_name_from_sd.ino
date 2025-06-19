#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for Serial port
  }

  if (!SD.begin()) {
    Serial.println("SD card initialization failed!");
    return;
  }

  File file = SD.open("/name.txt");
  if (!file) {
    Serial.println("Failed to open name.txt");
    return;
  }

  Serial.println("Reading contents of name.txt:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void loop() {
  // Nothing to do here
}
