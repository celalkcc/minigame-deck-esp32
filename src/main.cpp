#include <Arduino.h>

// including header files
#include "hardware_config.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp"

void setup() {
    Serial.begin(9600);
    Serial.println("MiniGame Deck - Version 0.99");

    millis();
    pinMode (startButton, INPUT_PULLUP);

}

void loop() {
}
