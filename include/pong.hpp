#ifndef PONG_HPP
#define PONG_HPP

#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "player.hpp"
#include "button.hpp"

// a class managing pong game with a state machine

class Pong {
    private:
        int scoreLeft;
        int scoreRight;
        Controller leftController;
        Controller rightController;

        Paddle leftPaddle;
        Paddle rightPaddle;

        Ball mainBall;
        myDisplay oledScreen;

        Player leftPlayer;
        Player rightPlayer;

        Button tactileStickMiddle;
        Button tactileStickLeft;
        Button tactileStickRight;
        Button tactileStickUp;
        Button tactileStickDown;

        Button leftButton;
        Button rightButton;

        enum pongStates{
            MENU,
            IN_GAME,
            PAUSE,
            THROW_IN,
            LEFT_WINS,
            RIGHT_WINS,
        };

        pongStates currentState;

    public:
        Pong();
        void begin();
        void update();
        void drawScreen();
        void checkScore();
        int getScoreLeft() const;
        int getScoreRight() const;
        void throwIn();
};


#endif