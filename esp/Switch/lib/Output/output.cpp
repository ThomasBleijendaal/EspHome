#include <Arduino.h>
#include <output.h>

int pin = 14;
bool pinState = false;

void OutputClass::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    pinState = false;
}

bool OutputClass::state() {
    return pinState;
}

void OutputClass::switchedOn() {
    digitalWrite(pin, HIGH);
    pinState = true;
}

void OutputClass::switchedOff() {
    digitalWrite(pin, LOW);
    pinState = false;
}
