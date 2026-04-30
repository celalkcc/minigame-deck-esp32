#include "input.hpp"
#include "conf.hpp"
#include "button.hpp"

Input::Input() 
    :   middle(MIDDLE),
        left(LEFT),
        right(RIGHT),
        up(UP),
        down(DOWN),
        leftPlayerButton(LEFT_PLAYER_BUTTON),
        rightPlayerButton(RIGHT_PLAYER_BUTTON)
{}


InputState Input::read() {
    InputState state;

    state.middle = middle.isPressed();
    state.left = left.isPressed();
    state.right = right.isPressed();
    state.up = up.isPressed();
    state.down = down.isPressed();
    state.leftActionButton = leftPlayerButton.isPressed();
    state.rightActionButton = rightPlayerButton.isPressed();
    
    return state;
}