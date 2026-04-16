#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

class Potentiometer {
    private:
        int value;
        int mappedValue;
        int pin;
        int screenHeight;
    public:
        Potentiometer(int pinNumber);
        int getMappedValue();

}; 

#endif