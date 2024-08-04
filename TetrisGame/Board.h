#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Parts.h"

using namespace std;
using namespace sf;

class Board : public Drawable
{
	private:
		Parts parts;
		int idNewPart, idColorNewPart;
		Color newPartColor;
		int indX, indY;
		int timer = 0;
		int limitTimer = 25;

		int board[24][12];
		RectangleShape boardShapes[24][12];
	public:
		Board(); //Constructor
		bool installPart(); //colocar piezas
		bool updateBoard(); //actualizar el tablero
		void updateBoardColors(); //actualizar los colores del tablero
		void updateLimitTimer(int); //actualizar el limite de caida de pieza
		void right();
		void left();
		void rotatePart();
		void CleanBoard(); //limpiar el tablero
		virtual void draw(RenderTarget&, RenderStates) const; //dibujar
};