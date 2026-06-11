#include <Arduino.h>
#include <output.h>

int pin = 14;
int brightness = 128;
bool pinState = false;

void OutputClass::begin() {
    pinMode(pin, OUTPUT);
    analogWrite(pin, 0);
    pinState = false;
}

bool OutputClass::state() {
    return pinState;
}

void OutputClass::setBrightness(int value) {
    brightness = (int)value;
}

void OutputClass::switchedOn() {
    analogWrite(pin, brightness);
    pinState = true;
}

void OutputClass::switchedOff() {
    analogWrite(pin, 0);
    pinState = false;
}
