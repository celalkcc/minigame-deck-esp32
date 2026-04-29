#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

// a class for game controllers. takes input from hardware, and maps the values to the playing field

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