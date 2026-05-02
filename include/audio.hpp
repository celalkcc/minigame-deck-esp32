#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Arduino.h>
#include "conf.hpp"

class Audio{
    private:
        unsigned volume;
        int buzzerTimer;
    public:
        Audio();
        void colision();

};



#endif