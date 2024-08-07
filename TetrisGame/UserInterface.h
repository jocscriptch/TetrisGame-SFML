#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class UserInterface : public Drawable
{
	private:
		Font font;
		Text scoreTextTitle;
		Text scoreText;
		Text maxScoreTextTitle;
		Text maxScore;
		Text dev;
		Text gameOverText;
		Text newScoreText;
		bool newScore = 0;
		bool gameOver = 0;

	public:
		UserInterface();
		void setScore(int);
		void setMaxCore(int);
		void gameOver();
		void newScore();
};