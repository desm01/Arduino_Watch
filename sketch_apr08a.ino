#include "SevSeg.h"
SevSeg sevseg; 

const unsigned long period = 1000; //one second
const unsigned long led_period = 500; //LED blink millisecond
unsigned long startMillis;
unsigned long led_startMillis;
unsigned long currentMillis;
unsigned long led_currentMillis;
const int hrs_btn = A0;
const int min_btn = A1;
const int ledPin = A2;
int Hrs = 22;
int Min = 35;
int Sec = 0;
int Time;
int ledState = LOW;

void setup(){
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop(){

 currentMillis = millis();
  if (currentMillis - startMillis >= period)
  {
    Sec = Sec + 1;
    startMillis = currentMillis;
  }
  
  if (Sec == 60)
  {
    Sec = 0;
    Min = Min + 1;
  }
  if (Min == 60)
  {
    Min = 0;
    Hrs = Hrs + 1;
  }
  if (Hrs == 13)
  {
    Hrs = 1;
  }
  Time = Hrs * 100 + Min;
  sevseg.setNumber(Time);
  sevseg.refreshDisplay();

}

void wait() {

}
