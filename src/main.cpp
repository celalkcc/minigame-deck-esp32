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

myDisplay oledScreen;
Input input;
Pong game;

HardwareSerial dfSerial(1);
DFRobotDFPlayerMini myDFPlayer;

// Global State Machine
enum DeviceState{
    START_MENU,
    SETTINGS_MENU,
    PONG_GAME
};
DeviceState currentState = START_MENU;



void setup() {
    Serial.begin(115200);
    dfSerial.begin(9600, SERIAL_8N1, DFPLAYER_RX, DFPLAYER_TX);

    // Initializing Hardware
    oledScreen.begin();
    oledScreen.clear();
    
    delay(1000);
    if (!myDFPlayer.begin(dfSerial)) {
        Serial.println("DFPlayer error");
        while(true);
    }
    myDFPlayer.volume(20);


    // Bootscreen
    oledScreen.drawBitmap();
    oledScreen.update();
    myDFPlayer.play(1);
    delay(4000);

    pinMode(LEFT, INPUT_PULLUP);
    pinMode(MIDDLE, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(LEFT_PLAYER_BUTTON, INPUT_PULLUP);
    pinMode(RIGHT_PLAYER_BUTTON, INPUT_PULLUP);
    pinMode(PASSIVE_BUZZER, OUTPUT);
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