/**
 *  Demo for the DoEvery library.
 *  
 *  This example blinks the LED every second. You
 *  can change the period by sending a numeric value through
 *  the serial monitor.
 */

#include <DoEvery.h>

DoEvery doEvery = DoEvery(1000);

void setup() {
  Serial.begin(115200);
  Serial.print("Starting Sketch\r\n Library Version: ");
  Serial.println(LIBRARY_VERSION);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if (doEvery.check()) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Serial.println("DoEvery Check.");
    doEvery.reset();
  }

  if (Serial.available() > 1) processSerial();
}

void processSerial() {
  doEvery.stop();
  String str = "";
  char c = (char)Serial.read();
  while (1)
  {
    if (isDigit(c))
      str += c;
    c = (char)Serial.read();
    if (c == '\n') break;
  }
  long period = str.toInt();
  if (period <= 0) {
    Serial.println("Invalid entry: " + str);
    doEvery.start();
    return;
  }
  doEvery.setPeriod(period);
  Serial.println("Reveied: " + str); 
}



