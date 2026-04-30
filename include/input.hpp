#ifndef INPUT_HPP
#define INPUT_HPP

#include "button.hpp"
#include "controller.hpp"

// hardware abstraction layer
// the struct InputState is passed to the game
struct InputState {
    bool left;
    bool right;
    bool up;
    bool down;
    bool middle;
    bool leftActionButton;
    bool rightActionButton;

    int leftController;
    int rightController;
};

// the Input class updates the snapshot of button values
// it returns the snapshot of type InputState via read(), 
class Input {
    private:
        Button middle;
        Button left;
        Button right;
        Button up;
        Button down;
        Button leftPlayerButton;
        Button rightPlayerButton;

        Controller leftPoti;
        Controller rightPoti;
    public:
        Input();
        InputState read();

};
#endif