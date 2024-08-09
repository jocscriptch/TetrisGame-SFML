#include "Sounds.h"

Sounds::Sounds()
{
    if (!music.openFromFile("music.ogg")) {
        cerr << "Error al cargar la música de fondo" << endl;
    }
    music.setLoop(true);
    music.setVolume(50);

    if (!lineSoundBuffer.loadFromFile("line.ogg")) {
        cerr << "Error al cargar el sonido de línea" << endl;
    }
    if (!newScoreSoundBuffer.loadFromFile("newScore.ogg")) {
        cerr << "Error al cargar el sonido de nuevo récord" << endl;
    }
    if (!gameOverSoundBuffer.loadFromFile("gameover.ogg")) {
        cerr << "Error al cargar el sonido de fin de juego" << endl;
    }

    lineSound.setBuffer(lineSoundBuffer);
    newScoreSound.setBuffer(newScoreSoundBuffer);
    gameOverSound.setBuffer(gameOverSoundBuffer);
}

void Sounds::playMusic()
{
    music.play();
}

void Sounds::pauseMusic()
{
    music.pause();
}

void Sounds::playLine()
{
    lineSound.play();
}

void Sounds::playNewScore()
{
    newScoreSound.play();
}

void Sounds::playGameOver()
{
    gameOverSound.play();
}