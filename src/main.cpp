#include <Arduino.h>

#define RED_DELAY 2000
#define YELLOW_DELAY 1000
#define GREEN_DELAY 3000

// Colors and corresponding pins
int red = 7;
int yellow = 6;
int green = 5;
// Array of colors
int colors[] = {red, yellow, green};
// For switching between colors and corresponding pins
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++){
    pinMode(colors[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int delayTime;
  switch (pos){
  case 0:
    delayTime = RED_DELAY;
    break;
  case 1:
    delayTime = YELLOW_DELAY;
    break;
  case 2:
    delayTime = GREEN_DELAY;
    break;
  default:
    delayTime = 0;
    break;
  }

  // Turns on light for a given time and turns it back off
  digitalWrite(colors[pos], HIGH);
  delay(delayTime);
  digitalWrite(colors[pos], LOW);

  // Update pos
  pos++;
  if (pos > 2) pos = 0;
}