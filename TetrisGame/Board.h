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

		int board[24][12];
		RectangleShape boardShapes[24][12];
	public:
		Board(); //Constructor
		bool installPart(); //colocar piezas
		void updateBoardColors(); //actualizar los colores del tablero
		void CleanBoard(); //limpiar el tablero
		virtual void draw(RenderTarget&, RenderStates) const; //dibujar
};