#include <FastLED.h>
#include <status.h>

CRGB leds[1];

void StatusDisplay::begin() {
    FastLED.addLeds<WS2812, 18, GRB>(leds, 0, 1);
    FastLED.setBrightness(20);
  
    fill_solid(leds, 1, CRGB::Magenta);
    FastLED.show();
}

void StatusDisplay::init() {
    fill_solid(leds, 1, CRGB::Orange);
    FastLED.show();
}

void StatusDisplay::connected() {
    fill_solid(leds, 1, CRGB::Teal);
    FastLED.show();
}

void StatusDisplay::switchedOn() {
    fill_solid(leds, 1, CRGB::Green);
    FastLED.show();
}

void StatusDisplay::switchedOff() {
    fill_solid(leds, 1, CRGB::Yellow);
    FastLED.show();
}
