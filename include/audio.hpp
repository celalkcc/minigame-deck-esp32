#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Arduino.h>
#include "conf.hpp"
#include "output.hpp"

class Audio{
    private:
        GameOutput& output;
        unsigned volume;
        int buzzerTimer;
    public:
        Audio(GameOutput& output);
        void playTone(int freq, int duration);
        void colision();
        void someoneJustScored();

};



#endif