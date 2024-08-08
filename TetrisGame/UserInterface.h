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
		Text maxScoreText;
		Text dev;
		Text gameOverText;
		Text newScoreText;
		bool newScore = 0;
		bool gameOver = 0;

	public:
		UserInterface();
		void SetScore(int);
		void SetMaxCore(int);
		void GameOver();
		void NewScore();
		virtual void draw(RenderTarget&, RenderStates) const;
};