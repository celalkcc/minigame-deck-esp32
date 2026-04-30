#ifndef PONG_HPP
#define PONG_HPP

#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "player.hpp"
#include "button.hpp"
#include "input.hpp"

// a class managing pong game with a state machine

class Pong {
    private:
        int scoreLeft;
        int scoreRight;

        Paddle leftPaddle;
        Paddle rightPaddle;

        Ball mainBall;
        //myDisplay oledScreen;

        Player leftPlayer;
        Player rightPlayer;

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
        void update(const InputState& input);
        void drawScreen(myDisplay& screen);
        void checkScore();
        int getScoreLeft() const;
        int getScoreRight() const;
        void throwIn();
};


#endif