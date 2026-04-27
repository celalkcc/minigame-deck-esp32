#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"


Pong::Pong()
    : scoreLeft(0),
    scoreRight(0),
    leftController(LEFT_POTI),
    rightController(RIGHT_POTI),
    leftPaddle(WALL_DISTANCE, 0, PADDLE_SIZE),
    rightPaddle(RIGHT_BORDER- WALL_DISTANCE, 0, PADDLE_SIZE),
    mainBall(),
    oledScreen(),
    currentState(MENU),
    leftPlayer(),
    rightPlayer(),

    tactileStickMiddle(MIDDLE),
    tactileStickLeft(LEFT),
    tactileStickRight(RIGHT),
    tactileStickUp(UP),
    tactileStickDown(DOWN),

    leftButton(LEFT_PLAYER_BUTTON),
    rightButton(RIGHT_PLAYER_BUTTON)
{}

void Pong::begin() { 
    oledScreen.begin();
}

void Pong::update() {
    switch (currentState) {
        case MENU:
            if(tactileStickMiddle.isPressed()) {
                currentState = IN_GAME;
            }
        break;

        case IN_GAME:
            leftPaddle.update(leftController.getValue());
            rightPaddle.update(rightController.getValue());
            mainBall.update(true, true);
            mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
            mainBall.bounceX(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
            mainBall.bounceX(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());   
            leftPlayer.addToScore(mainBall.checkScoreLeft());
            rightPlayer.addToScore(mainBall.checkScoreRight());
            if (mainBall.checkScoreLeft() || mainBall.checkScoreRight()){
                mainBall.resetToCenter();
                currentState = THROW_IN;
            }
            
            if (tactileStickMiddle.isPressed()) {
                currentState = PAUSE;
            }
        break;

        case PAUSE:
            leftPaddle.update(leftController.getValue());
            rightPaddle.update(rightController.getValue());
            oledScreen.drawScore(leftPlayer.getScore(), rightPlayer.getScore());
            if (tactileStickMiddle.isPressed()){
                currentState = IN_GAME;
           } 
        break;

        case THROW_IN:
            if (leftPlayer.getScore() > 4){
                leftPlayer.resetScore();
                rightPlayer.resetScore();
                currentState = LEFT_WINS;
            }
            if (rightPlayer.getScore() > 4){
                leftPlayer.resetScore();
                rightPlayer.resetScore();
                currentState = RIGHT_WINS;
            }
            leftPaddle.update(leftController.getValue());
            rightPaddle.update(rightController.getValue());
            mainBall.update(0, 1);
            mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
            if (tactileStickMiddle.isPressed()) {
                currentState = IN_GAME;
            }
        break;

        case LEFT_WINS:
            // Insert Bitmap image for left player wins
            currentState = MENU;
        break;

        case RIGHT_WINS:
        // insert bitmap iage for right player wins
        currentState = MENU;
        break;
    }
}

void Pong::drawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    oledScreen.drawPaddle(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
    oledScreen.drawPaddle(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());
    if (currentState == THROW_IN){
        oledScreen.drawScore(leftPlayer.getScore(), rightPlayer.getScore());
    }
    if (currentState == PAUSE){
        oledScreen.drawScore(leftPlayer.getScore(), rightPlayer.getScore());
        oledScreen.drawCenterLine();
    }
    if (currentState == IN_GAME){
        oledScreen.drawCenterLine();
    }
    
    oledScreen.update();
}

void Pong::throwIn() {
    mainBall.resetToCenter();
    mainBall.update(0,1);
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
}

