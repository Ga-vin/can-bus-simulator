#ifdef ENERGIA
	#include "Energia.h"
#else
	#include "Arduino.h"
#endif

#ifndef LED_PIN
	// Most Arduino boards already have a LED attached to pin 13 on the board itself
	#define LED_PIN 13
#endif

// STATES
#define STATE_OK            = 0x01
#define STATE_READING       = 0x02
#define STATE_WRITING       = 0x03
#define STATE_SIMULATING    = 0x04
#define STATE_EXITING       = 0x10
#define STATE_ERROR         = 0xA0

// SIGNALS
#define MSG_KEEPALIVE       = 0x01
#define MSG_READ            = 0x02
#define MSG_WRITE           = 0x03
#define MSG_DONE            = 0x04
#define MSG_EXIT            = 0x10
#define MSG_ERROR           = 0xA0

int state;

void setup() {
    // IO PORTS
    Serial.begin(9600);             // opens serial port, sets data rate to 9600 bps    

    pinMode(LED_PIN, OUTPUT);       // set pin as output

    state = OK;
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
