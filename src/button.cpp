#include <Arduino.h>
#include "button.hpp"
#include "conf.hpp"

Button::Button(int buttonPin){
    pin = buttonPin;
}
bool Button::isPressed(){
    if((millis() - debouncingTimer) <= BUTTON_DEBOUNCE_TIME) {
        return 0;
    }
    if (!digitalRead(pin)){
        debouncingTimer = millis();
        return 1;
    } else {
        return 0;
    }
}