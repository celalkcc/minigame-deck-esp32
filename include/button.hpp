#ifndef BUTTON_HPP
#define BUTTON_HPP

// a time based button debouncing class
class Button {
    private:
        int pin;
        unsigned long debouncingTimer;
    public:
        Button(int buttonPin);

        bool isPressed();
};


#endif