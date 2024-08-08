#include <iostream>
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "UserInterface.h"
#include <fstream>

using namespace std;
using namespace sf;

int main()
{
	Board board;
	UserInterface ui;

	RenderWindow window(VideoMode(600, 600), "Tetris");
	window.setFramerateLimit(60);

	board.installPart();

	int right = 0, left = 0, up = 0;
	int score = 0;
	int maxScore = 0;
	bool live = 1;

	fstream in("maxScore.txt");
	in >> maxScore;

	ui.SetMaxCore(maxScore);
	ui.SetScore(score);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();

		}
		
		if (live) {

			//rotacion
			if (Keyboard::isKeyPressed(Keyboard::Up) && !up)board.rotatePart(), up = 1;
			else if (!Keyboard::isKeyPressed(Keyboard::Up)) up = 0;

			// acelerar la caida de piezas
			if (Keyboard::isKeyPressed(Keyboard::Down)) board.updateLimitTimer(5);
			else board.updateLimitTimer(25);

			//mover las piezas a la derecha
			if (Keyboard::isKeyPressed(Keyboard::Right) && !right) {
				board.right();
				right = 1;
			}
			else if (!Keyboard::isKeyPressed(Keyboard::Right)) {
				right = 0;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right) && right) {
				right++;
				if (right == 6) right = 0;
			}

			//mover las piezas a la izquierda
			if (Keyboard::isKeyPressed(Keyboard::Left) && !left) {
				board.left();
				left = 1;
			}
			else if (!Keyboard::isKeyPressed(Keyboard::Left)) {
				left = 0;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left) && left) {
				left++;
				if (left == 6) left = 0;
			}

			if (board.updateBoard()) {
				if (!board.installPart()) {
					live = 0;
					if (score > maxScore) {
						ui.NewScore();
						ofstream out("maxScore.txt");
						out << score;
					}
					else {
						ui.GameOver();
					}
				}
			}
			board.updateBoardColors();

			int newScore = board.checkLine() * 5;
			score += newScore;
			ui.SetScore(score);
		}
		window.clear(Color(20, 20, 20));
		window.draw(board);
		window.draw(ui);
		window.display();
	}
	return 0;
}