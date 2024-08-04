#include <iostream>
#include "SFML/Graphics.hpp"
#include "Board.h"

using namespace std;
using namespace sf;

int main()
{
	Board board;
	RenderWindow window(VideoMode(600, 600), "Tetris");
	window.setFramerateLimit(60);

	board.installPart();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();

		}
		board.updateBoardColors();
		window.clear(Color(20, 20, 20));
		window.draw(board);
		window.display();

	}
	return 0;
}