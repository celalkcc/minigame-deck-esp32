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
        Audio(GameOutput& output);              // reads the game state from output abstraction layer
        void playTone(int freq, int duration);  // used by other funcitons to play melodys
        void colision();                        // small blip
        void someoneJustScored();                  // plays a downgoing melody because someone lost a point

};



#endif