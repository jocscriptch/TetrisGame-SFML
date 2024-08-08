#include "Sounds.h"

Sounds::Sounds()
{
	music.openFromFile("music.ogg");
	music.setLoop(true);
	music.setVolume(50);

	if (!lineSoundBuffer.loadFromFile("line.ogg")) {
		cout << "Error al cargar sonido de linea" << endl;
	}
	if (!newScoreSoundBuffer.loadFromFile("newScore.ogg")) {
		cout << "Error al cargar sonido record" << endl;
	}
	if (!gameOverSoundBuffer.loadFromFile("gameover.ogg")) {
		cout << "Error al cargar sonido gameover" << endl;
	}

	lineSound.setBuffer(lineSoundBuffer);
	newScoreSound.setBuffer(newScoreSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

void Sounds::PlayMusic()
{
	music.play();

}
void Sounds::PauseMusic()
{
	music.pause();
}

void Sounds::PlayLine()
{
	lineSound.play();
}

void Sounds::PlayNewScore()
{
	newScoreSound.play();
}

void Sounds::PlayGameOver()
{
	gameOverSound.play();
}