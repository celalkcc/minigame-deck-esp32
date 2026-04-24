#include <Arduino.h>
#include <Wire.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"
#include "conf.hpp"

Pong game;

void setup() {
    Serial.begin(9600);
    Serial.println("MiniGame Deck - Version 0.99");
    millis();
    pinMode(LEFT, INPUT_PULLUP);
    pinMode(MIDDLE, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    
    game.begin();
}


void loop() {
    game.update();
    game.drawScreen();
    game.addToScore();
}
