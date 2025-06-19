#include <Arduino.h>

static String name = "";
static bool gotName = false;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Enter your name:");
}

void loop() {
  if (!gotName) {
    if (Serial.available()) {
      name = Serial.readStringUntil('\n');
      name.trim();
      gotName = true;
    }
    return;
  }

  Serial.print("Hello, ");
  Serial.println(name);
  delay(1000);
}
