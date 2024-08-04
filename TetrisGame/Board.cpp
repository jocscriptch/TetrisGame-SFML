#include "Board.h"

Board::Board() // def constructor
{
	memset(board, 0, sizeof(board));
	for (int i = 0; i < 24; i++){
		for (int j = 0; j < 12; j++){
			boardShapes[i][j] = RectangleShape(Vector2f(25, 25));
			boardShapes[i][j].setPosition(j * 25, i * 25);
			boardShapes[i][j].setFillColor(Color(50, 50, 50));
			boardShapes[i][j].setOutlineThickness(1);
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


bool Board::updateBoard()
{
	bool limit = 0;
	int aux;

	if (timer >= limitTimer) {
		aux = 0;
		for (int i = 22; i >= 0; i--) {
			for (int j = 0; j < 12; j++) {
				if (board[i][j] == -1) {
					if (board[i + 1][j] <= 0) aux++;
			     }
		     }
	    }

		if (aux == 4) {
			indY++;
			for (int i = 22; i >= 0; i--) {
				for (int j = 0; j < 12; j++) {
					if (board[i][j] == -1) {
						board[i][j] = 0;
						board[i + 1][j] = -1;
					}
				}
			}
		}else {
			for (int i = 23; i >= 0; i--) {
				for (int j = 0; j < 12; j++) {
					if (board[i][j] == -1) board[i][j] = idColorNewPart;
				}
			}
			limit = 1;
		}
		timer = 0;
	}
	timer++;
	return limit;
}

void Board::updateBoardColors()
{
	for (int i = 0; i < 24; i++){
		for (int j = 0; j < 12; j++){
			switch (board[i][j]) {
			case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;
			case 1: boardShapes[i][j].setFillColor(Color(10, 210, 255)); break;
			case 2: boardShapes[i][j].setFillColor(Color(41, 98, 255)); break;
			case 3: boardShapes[i][j].setFillColor(Color(149, 0, 255)); break;
			case 4: boardShapes[i][j].setFillColor(Color(255, 0, 89)); break;
			case 5: boardShapes[i][j].setFillColor(Color(255, 140, 0)); break;
			case 6: boardShapes[i][j].setFillColor(Color(180, 230, 0)); break;
			case 7: boardShapes[i][j].setFillColor(Color(15, 255, 219)); break;

			default:
				boardShapes[i][j].setFillColor(newPartColor);
				break;
			}
		}
	}
}

void Board::updateLimitTimer(int limit)
{
	limitTimer = limit;
}

//mover piezas hacia la derecha
void Board::right() {
	int aux = 0;
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 11; j++) {
			if (board[i][j] == -1) {
				if (board[i][j + 1] <= 0) {
					aux++;
				}
			}
		}
	}

	if (aux == 4) {
		indX++;
		for (int i = 0; i < 24; i++) {
			for (int j = 11; j >= 0; j--) {
				if (board[i][j] == -1) board[i][j] = 0, board[i][j + 1] = -1;
			}
		}
	}
}

void Board::left() {
	int aux = 0;
	for (int i = 0; i < 24; i++) {
		for (int j = 1; j < 12; j++) {
			if (board[i][j] == -1) {
				if (board[i][j - 1] <= 0) {
					aux++;
				}
			}
		}
	}

	if (aux == 4){
		indX--;
		for (int i = 0; i < 24; i++){
			for (int j = 0; j < 12; j++){
				if (board[i][j] == -1) board[i][j] = 0, board[i][j - 1] = -1;
			}
		}
	}
}

//metodo de rotar las piezas cuando caen
void Board::rotatePart() {
	parts.rotatePart(idNewPart);
	vector<vector<bool>> part = parts.consultPart(idNewPart);

	int size = (int)part.size();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (part[i][j]) {
				if (indY + i < 0 || indY + i >= 24 || indX + j < 0 || indX + j >= 12 || board[indY + i][indX + j]>0) {
					parts.unRotatePart(idNewPart);
					return;
				}
			}
		}
	}

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 12; j++) {
			if (board[i][j] == -1) board[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (part[i][j]) {
				board[i + indY][j + indX] = -1;
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