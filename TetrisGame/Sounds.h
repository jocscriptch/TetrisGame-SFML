#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Sounds
{
    private:
        Music music;
        Sound lineSound;
        Sound newScoreSound;
        Sound gameOverSound;
        SoundBuffer lineSoundBuffer;
        SoundBuffer newScoreSoundBuffer;
        SoundBuffer gameOverSoundBuffer;

    public:
        Sounds();  // Constructor
        void playMusic();     // Reproduce la musica de fondo
        void pauseMusic();    // Pausa la musica
        void playLine();      // Reproduce el sonido de linea completada
        void playNewScore();  // Reproduce el sonido de nuevo record
        void playGameOver();  // Reproduce el sonido de gameover
};