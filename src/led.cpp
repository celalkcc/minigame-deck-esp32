#include <FastLED.h>
#include "led.hpp"
#include "conf.hpp"



LedStrip::LedStrip(){
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
}
