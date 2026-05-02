#ifndef PONG_HPP
#define PONG_HPP

#include <DFRobotDFPlayerMini.h>

#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "player.hpp"
#include "button.hpp"
#include "input.hpp"
#include "audio.hpp"
#include "output.hpp"

// a class managing pong game with a state machine

class Pong {
    private:

        GameOutput& output;
        int scoreLeft;
        int scoreRight;

        Paddle leftPaddle;
        Paddle rightPaddle;

        Ball mainBall;

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
        Pong(GameOutput& state);
        void begin();
        void update(const InputState& input);
        void drawScreen(myDisplay& screen);
        void checkScore();
        int getScoreLeft() const;
        int getScoreRight() const;
        void throwIn();
};


#endif