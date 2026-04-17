#include <Arduino.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"

void setup() {
    Serial.begin(9600);
    Serial.println("MiniGame Deck - Version 0.99");

    millis();
}

void loop() {
    pongUpdate();    
    pongDrawScreen();
}
