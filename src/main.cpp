#include <Arduino.h>
#include <Wire.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"
#include "conf.hpp"

myDisplay oledScreen;


void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.print("MiniGame Deck - Version 0.99");
    oledScreen.begin();
    oledScreen.clear();
    oledScreen.drawBitmap();
    oledScreen.update();
    delay(4000);
    pinMode(LEFT, INPUT_PULLUP);
    pinMode(MIDDLE, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(LEFT_PLAYER_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_PLAYER_BUTTON, INPUT_PULLUP);
    
}

void loop() {
    static Pong game;
    game.update();
    game.drawScreen(oledScreen);
}
