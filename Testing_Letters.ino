/*  Testing Letters - Print a string of array-based letters, and
 *  change them when the button is pressed.
 *  Written by Finnbar Keating for TWSU
 *  CC-Attribution-BY-ShareAlike
 */

const int frameRate = 30; 
const int framePeriod = 1e6/frameRate; 
unsigned long lastMicros = 0;

#include "fonts.h"
#include "letters.h"
#include "touch.h"
#include "dmx.h"
const int numLEDs = 174;
const int DMXframeSize = 180; // six extra bytes to keep Mike's drivers happy
const int LEDpin = 9;
const int MIC = A0;    //analog 0
const int SDPOWER = 6;    //needs to be LOW to enable SD power -> 3.3V
unsigned char DMXframe[DMXframeSize];  //all the general DMX stuff
int value = 0;

void setup() {
  setupDMX(DMXframe);
  pinMode(SDPOWER, OUTPUT);
  digitalWrite(SDPOWER, LOW);
}

void loop() {
  for(value = 0; value < 66; value++) {
    alphabet(); //place a letter in the starting area (the far edge of the bright eyes)
    for(int a = 0; a < 8; a++) {
      playLetter();  //move all letters on one pixel (to the left)
      convert();
      sendDMX(DMXframe, DMXframeSize);
      delay(100);
    }
  }
}

void convert() {
  for(int q = 0; q < 180; q++) {
    DMXframe[q] = DMXreturn[q];    //as DMXframe cannot be multiply defined
  }                                //in different files of the same
  for(int q = 0; q < 180; q++) {   //folder, it gets put into the
    DMXreturn[q] = 0;              //frame here.
  }
}

void alphabet() {
  if(readTouch()) {
    startLetter(aUpper);
  } else {
    startLetter(aLower);
  }
}
