#include <Arduino.h>
#include <output.h>

int pin = 14;
int brightness = 128;
bool pinState = false;

void setOff(int pin) {
    ledcDetachPin(pin);

    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void setOutput(int pin, int value) {
    pinMode(pin, OUTPUT);
    analogWrite(pin, value);
}

void OutputClass::begin() {
    setOff(pin);

    pinState = false;
}

bool OutputClass::state() {
    return pinState;
}

void OutputClass::setBrightness(int value) {
    brightness = (int)value;
}

void OutputClass::switchedOn() {
    setOutput(pin, brightness);
    pinState = true;
}

void OutputClass::switchedOff() {
    setOff(pin);
    pinState = false;
}

