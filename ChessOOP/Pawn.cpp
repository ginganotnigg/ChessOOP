#include "Pawn.h"


Pawn::Pawn(char _symbol) : Piece(_symbol)
{
	if (symbol == 'P') img.loadFromFile("img/P.png");
	else img.loadFromFile("img/p.png");
	img_size = img.getSize();
	sprite.setTexture(img);
}

Pawn::~Pawn()
{
}