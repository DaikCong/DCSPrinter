#include <Arduino.h>

static String firstName = "";
static String lastName = "";
static bool gotFirstName = false;
static bool gotLastName = false;


void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  Serial.println("Enter your first name:");
}

void loop() {
  if (!gotFirstName) {
    if (Serial.available()) {
      firstName = Serial.readStringUntil('\n');
      firstName.trim();
      gotFirstName = true;
      Serial.println("Enter your last name:");
    }
    return;
  }

  if (!gotLastName) {
    if (Serial.available()) {
      lastName = Serial.readStringUntil('\n');
      lastName.trim();
      gotLastName = true;

    }
    return;
  }

  Serial.print("Hello, ");

  Serial.print(firstName);
  Serial.print(" ");
  Serial.println(lastName);

  delay(1000);
}
