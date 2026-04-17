#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

class Controller {
    private:
        int value;
        int mappedValue;
        int pin;
    public:
        Controller(int pinNumber);
        int getValue();

}; 

#endif