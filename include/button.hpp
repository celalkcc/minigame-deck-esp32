class Button {
    private:
        int pin;
        unsigned long debouncingTimer;
    public:
        Button(int buttonPin);

        bool isPressed();
};