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

bool Board::installPart() {
	srand(time(NULL));
	idNewPart = rand() % 7;

	vector<vector<bool>> part = parts.consultPart(idNewPart);

	int size = (int)part.size();

	indY = 0;
	indX = 5 - size / 2;
	

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (part[i][j]) {
				if (board[i][j + indX] > 0) return false;
				board[i][j + indX] = -1;
			}
		}
	}

	int color = 1 + rand() % 7;
	idColorNewPart = color;

	switch (color) {
		case 1: newPartColor = Color(10, 210, 255); break;
		case 2: newPartColor = Color(41, 98, 255); break;
		case 3: newPartColor = Color(149, 0, 255); break;
		case 4: newPartColor = Color(255, 0, 89); break;
		case 5: newPartColor = Color(255, 140, 0); break;
		case 6: newPartColor = Color(180, 230, 0); break;
		case 7: newPartColor = Color(15, 255, 219); break;
	}
	return true;
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

			default:
				boardShapes[i][j].setFillColor(newPartColor);
				break;
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