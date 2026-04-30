#ifndef AUDIO_HPP
#define AUDIO_HPP

class Audio{
    private:
        int dfVolume;
        int currentSong;

    public:
        Audio();
        void passiveBuzzer(int soundSelector);
        void selectPlaylist(int playlistSelector);
        void playSong(int songSelector);
        void playAdvert();
};



#endif