#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "player.hpp"
#include "button.hpp"



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

        Button middleButton;

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