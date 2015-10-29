#ifdef ENERGIA
	#include "Energia.h"
#else
	#include "Arduino.h"
#endif

#ifndef LED_PIN
	// Most Arduino boards already have a LED attached to pin 13 on the board itself
	#define LED_PIN 13
#endif


void setup() {
    // IO PORTS
    Serial.begin(9600);             // opens serial port, sets data rate to 9600 bps
    Serial1.begin(9600);             // opens serial port, sets data rate to 9600 bps

    pinMode(LED_PIN, OUTPUT);       // set pin as output
}

void loop() {

    //Wait for serial input
    while (!Serial.available()) { delay(10); }

    delay(10);
    String readString;

    while (Serial.available() > 0) {
        char c = Serial.read();     //gets one byte from serial buffer
        readString += c;            //makes the string readString
    }
    Serial.write(readString.c_str());
}
