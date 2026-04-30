#include <FastLED.h>
#include "led.hpp"
#include "conf.hpp"



LedStrip::LedStrip(){
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
}

void LedStrip::ambientGlow(){
    static uint16_t t = 0;
    t += 3; // faster

    for(int i = 0; i < NUMBER_OF_LEDS; i++){
        uint8_t wave = sin8(t + i * 25);

        // slightly brighter now
        uint8_t brightness = scale8(wave, 100); 

        // purple range (around 200–230 hue)
        leds[i] = CHSV(210 + sin8(t / 6) / 20, 180, brightness);
    }

    FastLED.show();
}