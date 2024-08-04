#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>


class Board : public Drawable
{
private:
	int board[20][10];
	RectangleShape boardShapes[20][10];

public:
	Board();
	void updateBoardColor();
	virtual void draw(RenderTarget&, SFML_RENDERSTATES_HPP)
};
