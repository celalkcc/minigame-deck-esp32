#include <FastLED.h>
#include "led.hpp"
#include "conf.hpp"
#include "output.hpp"



LedStrip::LedStrip() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
}

void LedStrip::greetingBlink(){
    for (int i = 0; i < numberOfBlinks; i++) {
        FastLED.setBrightness(10);
        fill_solid(leds, NUMBER_OF_LEDS, CRGB::Green);
        FastLED.show();
        delay(greetingIntervall);
        fill_solid(leds, NUMBER_OF_LEDS, CRGB::Black);
        FastLED.show();
        delay(greetingIntervall);
    }
}

void LedStrip::showScore(int leftScore, int rightScore) {
    FastLED.setBrightness(15);
    fill_solid(leds, NUMBER_OF_LEDS, CRGB::Black);
    for (int i = 0; i < leftScore; i++){
        leds[i] = CRGB::Red;
    }

    for (int i = 0; i < rightScore; i++) {
        leds[NUMBER_OF_LEDS -1 -i] = CRGB::Blue; 
    }
    
    FastLED.show();
}
void LedStrip::resetLEDs(){
    fill_solid(leds, NUMBER_OF_LEDS, CRGB::Black);
    FastLED.show();
}


