#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

// a class for game controllers. takes input from hardware, and maps the values to the playing field

class Controller {
    private:
        int value;                      // input value from hardware
        int mappedValue;                // mapped value for the input abstraction layer to read
        int pin;                        // hardware pin
    public:
        Controller(int pinNumber);      
        int getValue();

}; 

#endif