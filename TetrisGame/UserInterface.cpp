#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("Tetris.ttf")) {
		cout << "Error al cargar fuente" << endl;
	}
	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(Color::White);
	scoreTextTitle.setPosition(Vector2f(235, 25));
	scoreTextTitle.setString("Puntuación");

	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(Color::White);
	maxScoreTextTitle.setPosition(Vector2f(235, 200));
	maxScoreTextTitle.setString("Puntuación Máxima");
	maxScoreTextTitle.setCharacterSize(20);

	scoreText.setFont(font);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(250, 70));
	
	maxScore.setFont(font);
	maxScore.setFillColor(Color::White);
	maxScore.setPosition(Vector2f(265, 245));

	dev.setFont(font);
	dev.setFillColor(Color::White);
	dev.setPosition(Vector2f(260, 370));
	dev.setString("By Jocscripth");
	dev.setCharacterSize(20);

	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(Vector2f(8, 150));
	gameOverText.setString("Perdiste");
	gameOverText.setCharacterSize(25);

	newScoreText.setFont(font);
	newScoreText.setFillColor(Color::White);
	newScoreText.setPosition(Vector2f(8, 150));
	newScoreText.setString("Nueva Puntuación");
	newScoreText.setCharacterSize(25);
}

void UserInterface::setScore(int score) 
{

}