#include <Arduino.h>
#include "controller.hpp"
#include "conf.hpp"

Controller::Controller(int pinNumber){
    pin = pinNumber;
}

int Controller::getValue() {
    value = analogRead(pin);
    mappedValue = map(value, 0, 4095, UPPER_BORDER, LOWER_BORDER - PADDLE_SIZE);
    return mappedValue;
}