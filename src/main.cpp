#include <Arduino.h>
#include <Wire.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"
#include "conf.hpp"
#include "button.hpp"
#include "input.hpp"

myDisplay oledScreen;
Input input;
Pong game;

// Global State Machine
enum DeviceState{
    START_MENU,
    SETTINGS_MENU,
    PONG_GAME
};
DeviceState currentState = START_MENU;



void setup() {

    // Initializing Hardware
    Serial.begin(115200);
    delay(2000);
    Serial.print("MiniGame Deck - Version 0.99");
    oledScreen.begin();
    oledScreen.clear();
    delay(1000);

    // Bootscreen
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
    
    InputState state = input.read();

    switch (currentState) {
        case START_MENU:
            if(state.middle) {
                currentState = PONG_GAME;
            }
            break;
        
        case SETTINGS_MENU:
            // add settings menu
            break;
        case PONG_GAME:
            game.update(state);
            game.drawScreen(oledScreen);
            break;
    }
    
}