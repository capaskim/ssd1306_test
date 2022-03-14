#include <Arduino.h>
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"
#include "dialog_14.h"

#define SDA 10
#define SCL 9

SSD1306Wire display(0x3c, SDA, SCL);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(Dialog_plain_14);

  char buffer[50];
  for (int i = 0; i<=100; i++) {
    display.clear();
    Serial.println(i);
    display.drawStringf(0, 0, buffer, "Hello World %d", i);
    display.display();
    delay(300);
  }  
}

void loop() {
  // put your main code here, to run repeatedly:
}