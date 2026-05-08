#ifndef LED_HPP
#define LED_HPP

#include <FastLED.h>
#include "conf.hpp"
#include "output.hpp"

class LedStrip {
    private:
        int greetingIntervall = 70;
        int numberOfBlinks = 4;
        CRGB leds[NUMBER_OF_LEDS];
    public:
        LedStrip();
        void showScore(int, int);
        void greetingBlink();
        void resetLEDs();
};



#endif