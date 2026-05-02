#include "audio.hpp"

Audio::Audio() {
    ledcSetup(BUZZER_LEDC_CHANNEL, 2000, 8);
    ledcAttachPin(PASSIVE_BUZZER, BUZZER_LEDC_CHANNEL);
    volume = dfPlayerStartVolume;
}

void Audio::colision() {
    ledcWriteTone(BUZZER_LEDC_CHANNEL, 1000);
    delay(500);
}


