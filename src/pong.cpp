#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "input.hpp"


Pong::Pong()
    : scoreLeft(0),
    scoreRight(0),
    leftController(LEFT_POTI),
    rightController(RIGHT_POTI),
    leftPaddle(WALL_DISTANCE, 0, PADDLE_SIZE),
    rightPaddle(RIGHT_BORDER- WALL_DISTANCE, 0, PADDLE_SIZE),
    mainBall(),
    //oledScreen(),
    currentState(MENU),
    leftPlayer(),
    rightPlayer()

{}


void Pong::update(const InputState& input) {
    switch (currentState) {
        case MENU:
            
            if(input.middle) {
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
            
            if (input.middle) {
                currentState = PAUSE;
            }
        break;

        case PAUSE:
            leftPaddle.update(leftController.getValue());
            rightPaddle.update(rightController.getValue());
            if (input.middle){
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
            if (input.middle) {
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

void Pong::drawScreen(myDisplay& screen) {
    screen.clear();
    screen.drawPixel(mainBall.getX(), mainBall.getY());
    screen.drawPaddle(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
    screen.drawPaddle(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());
    if (currentState == THROW_IN){
        screen.drawScore(leftPlayer.getScore(), rightPlayer.getScore());
    }
    if (currentState == PAUSE){
        screen.drawScore(leftPlayer.getScore(), rightPlayer.getScore());
        screen.drawCenterLine();
    }
    if (currentState == IN_GAME){
        screen.drawCenterLine();
    }
    
    screen.update();
}

void Pong::throwIn() {
    mainBall.resetToCenter();
    mainBall.update(0,1);
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
}

