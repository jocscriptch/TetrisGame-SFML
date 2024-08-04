#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

using namespace std;
using namespace sf;

class Board : public Drawable
{
private:
	int board[24][12];
	RectangleShape boardShapes[24][12];
public:
	Board(); //Constructor
	void updateBoardColors(); //actualizar los colores del tablero
	void CleanBoard(); //limpiar el tablero
	virtual void draw(RenderTarget&, RenderStates) const; //dibujar
};