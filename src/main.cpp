#include <Arduino.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"
#include "conf.hpp"
#include "button.hpp"
#include "input.hpp"
#include "led.hpp"
#include "audio.hpp"

myDisplay oledScreen;
Input input;
GameOutput gameOutput;
LedStrip myLEDs;
Audio mySound(gameOutput);
Pong game(gameOutput, myLEDs);



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
    oledScreen.begin();
    delay(500);
    oledScreen.clear();

    myLEDs.greetingBlink();
    
    
    


    // Bootscreen
    oledScreen.drawBitmap();
    oledScreen.update();
    //myDFPlayer.play(2);
    delay(2000);

    pinMode(LEFT, INPUT_PULLUP);
    pinMode(MIDDLE, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(LEFT_PLAYER_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_PLAYER_BUTTON, INPUT_PULLUP);

}

void loop() {
    InputState gameInput = input.read(); 

    switch (currentState) {
        case START_MENU:
            if(gameInput.middle) {
                currentState = PONG_GAME;
            }
            break;
        
        case SETTINGS_MENU:
            // add settings menu
            break;
        case PONG_GAME:
            game.update(gameInput);
            game.drawScreen(oledScreen);
            mySound.colision();
            mySound.someoneJustScored();
            mySound.actionButton();
            break;
    }
    
}