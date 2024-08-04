#include "Board.h"

Board::Board() // def constructor
{
	memset(board, 0, sizeof(board));
	for (int i = 0; i < 24; i++){
		for (int j = 0; j < 12; j++){
			boardShapes[i][j] = RectangleShape(Vector2f(25, 25));
			boardShapes[i][j].setPosition(j * 25, i * 25);
			boardShapes[i][j].setFillColor(Color(50, 50, 50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(Color(0,0,0));
		}
	}
}

void Board::updateBoardColors()
{
	for (int i = 0; i < 24; i++){
		for (int j = 0; j < 12; j++){
			switch (board[i][j]) {
			case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;
			case 1: boardShapes[i][j].setFillColor(Color(255, 166, 50)); break;
			case 2: boardShapes[i][j].setFillColor(Color(245, 152, 245)); break;
			case 3: boardShapes[i][j].setFillColor(Color(51, 204, 153)); break;
			case 4: boardShapes[i][j].setFillColor(Color(255, 110, 110)); break;
			case 5: boardShapes[i][j].setFillColor(Color(255, 204, 77)); break;
			case 6: boardShapes[i][j].setFillColor(Color(166, 166, 255)); break;
			case 7: boardShapes[i][j].setFillColor(Color(138, 194, 247)); break;
			}
		}
	}
}

void Board::draw(RenderTarget& rt, RenderStates rs) const
{
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 12; j++) {
			rt.draw(boardShapes[i][j], rs);
		}
	}
}