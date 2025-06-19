#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

void readFileAndPrint(const char* path) {
  File file = SD.open(path);
  if (!file) {
    Serial.print("Failed to open ");
    Serial.println(path);
    return;
  }
  Serial.print("Reading file: ");
  Serial.println(path);
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  if (!SD.begin()) {
    Serial.println("SD card initialization failed!");
    return;
  }

  readFileAndPrint("/name.txt");
}

void loop() {
  // Nothing to do here
}
