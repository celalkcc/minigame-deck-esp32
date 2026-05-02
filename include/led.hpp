#ifndef LED_HPP
#define LED_HPP

#include <FastLED.h>
#include "conf.hpp"

class LedStrip {
    private:
        CRGB leds[NUMBER_OF_LEDS];
    public:
        LedStrip();
};


#endif