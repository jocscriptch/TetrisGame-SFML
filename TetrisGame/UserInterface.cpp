#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("Luckiest.ttf")) {
		cout << "Error al cargar fuente" << endl;
	}
	// Titulo de la puntuacion actual del jugador
	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(Color::Yellow);
	scoreTextTitle.setPosition(Vector2f(365, 150));
	scoreTextTitle.setString("Puntuación");

	// Record maximo del jugador
	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(Color::Magenta);
	maxScoreTextTitle.setPosition(Vector2f(400, 300));
	maxScoreTextTitle.setString("Récord");

	// muestra la puntacion numerica
	scoreText.setFont(font);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(415, 200));
	
	// muestra el record numerico
	maxScoreText.setFont(font);
	maxScoreText.setFillColor(Color::White);
	maxScoreText.setPosition(Vector2f(415, 350));

	// desarrollador
	dev.setFont(font);
	dev.setFillColor(Color::Cyan);
	dev.setPosition(Vector2f(394, 555));
	dev.setString("\t\t\t\tBy\n\tjocscriptch");
	dev.setCharacterSize(15);

	// titulo de gameover
	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(Vector2f(80, 150));
	gameOverText.setString("¡GameOver!");
	gameOverText.setCharacterSize(25);

	// titulo de nueva puntuacion
	newScoreText.setFont(font);
	newScoreText.setFillColor(Color::Green);
	newScoreText.setPosition(Vector2f(365, 50));
	newScoreText.setString("¡Nuevo Récord!");
	newScoreText.setCharacterSize(25);
}

void UserInterface::SetScore(int score) 
{
	if (score <= 9) scoreText.setString("000" + to_string(score));
	else if (score <= 99) scoreText.setString("00" + to_string(score));
	else if (score <= 999) scoreText.setString("000" + to_string(score));
	else if (score <= 9999) scoreText.setString(to_string(score));
	else scoreText.setString("9999");
}

void UserInterface::SetMaxCore(int max)
{
	if (max <= 9) maxScoreText.setString("000" + to_string(max));
	else if (max <= 99) maxScoreText.setString("00" + to_string(max));
	else if (max <= 999) maxScoreText.setString("000" + to_string(max));
	else if (max <= 9999) maxScoreText.setString(to_string(max));
	else maxScoreText.setString("9999");
}

void UserInterface::GameOver() { gameOver = 1; }

void UserInterface::NewScore() { newScore = 1; }

void UserInterface::draw(RenderTarget &rt, RenderStates rs)const
{
	rt.draw(scoreTextTitle, rs);
	rt.draw(scoreText, rs);
	rt.draw(maxScoreTextTitle, rs);
	rt.draw(maxScoreText, rs);
	rt.draw(dev, rs);
	if (gameOver) rt.draw(gameOverText, rs);
	if (newScore) rt.draw(newScoreText, rs);
}