#include <Arduino.h>
#include "input_conf.hpp"
#include "display.hpp"
#include "conf.hpp"

Potentiometer::Potentiometer(int pinNumber){
    pin = pinNumber;
}

int Potentiometer::getMappedValue() {
    value = analogRead(pin);
    mappedValue = map(value, 0, value, 0, SCREEN_HEIGHT);
    return mappedValue;
}