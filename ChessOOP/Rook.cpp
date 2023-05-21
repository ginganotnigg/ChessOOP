#include"Rook.h"
#include"Square.h"
#include <SFML/Graphics.hpp>

Rook::Rook(const char name): Piece(name) {
	if (name == 'R') img.loadFromFile("Image/wR.png");
	else img.loadFromFile("Image/bR.png");
	//imageSize = img.getSize();
	sprite.setTexture(img);

}

bool Rook::isValidMove() {
	
		return false;

}

vector<Square*> Rook::getValidMoves() {
	vector<Square*> squares;
	// Rook moves
	for (int i = 1; i <= 8; i++)
	{
		if (i != position->row) squares.push_back(new Square(position->column, i));
	}
	for (int j = 'a'; j <= 'h'; j++)
	{
		if (j != position->column) squares.push_back(new Square(char(j), position->row));
	}
	
	return squares;
}


