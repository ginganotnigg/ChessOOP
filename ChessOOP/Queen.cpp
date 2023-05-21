#include "Queen.h"

Queen::Queen(char name) : Piece(name)
{
	if (name == 'Q') img.loadFromFile("Image/wQ.png");
	else img.loadFromFile("Image/bQ.png");

	sprite.setTexture(img);
}

Queen::~Queen()
{

}

vector<Square*> Queen::getValidMoves()
{
	vector<Square*> squares;
	// Rook moves
	for (int i = 1; i <= 8; i++)
	{
		if (i != getCurrentPosition()->row) squares.push_back(new Square(getCurrentPosition()->column, i));
	}
	for (int j = 'a'; j <= 'h'; j++)
	{
		if (j != getCurrentPosition()->column) squares.push_back(new Square(j, getCurrentPosition()->row));
	}
	// Bishop moves
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 'a'; j <= 'h'; j++)
		{
			if ((i != getCurrentPosition()->row && j != int(getCurrentPosition()->column)) && (abs(i - getCurrentPosition()->row) == abs(j - int(getCurrentPosition()->column))))
			{
				squares.push_back(new Square(char(j), i));
			}
		}
	}
	return squares;
}

bool Queen::isValidMove()
{
	return 0;
}
