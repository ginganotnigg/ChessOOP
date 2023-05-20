#include "Pawn.h"


Pawn::Pawn(char _symbol) : Piece(_symbol)
{
	if (symbol == 'P') img.loadFromFile("img/wP.png");
	else img.loadFromFile("img/bP.png");
	img_size = img.getSize();
	sprite.setTexture(img);
}

Pawn::~Pawn()
{
}
