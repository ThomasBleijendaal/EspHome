#include <Arduino.h>
#include <output.h>

int pin = 1;

void OutputClass::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void OutputClass::switchedOn() {
    digitalWrite(pin, HIGH);
}

void OutputClass::switchedOff() {
    digitalWrite(pin, LOW);
}
