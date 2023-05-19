#include "Queen.h"

Queen::Queen()
{
	if (name = 'Q') img.loadFromFile("Image/wQ.png");
	else img.loadFromFile("Image/bQ.png");
	
	sprite.setTexture(img);
}

Queen::~Queen()
{

}

vector<Square> Queen::getValidMoves()
{
	vector<Square> squares;
	for (int i = 1; i <= 8; i++)
	{
		if (i != i != getCurrentPosition().row) squares.push_back(Square(getCurrentPosition().col, i));
	}
	for (int j = int('a'); j <= int('h'); j++)
	{
		if(j != getCurrentPosition().col) squares.push_back(Square(char(j), getCurrentPosition().row));
	}
	for (int i = 1; i <= 8; i++)
	{
		for (int j = int('a'); j <= int('h'); j++)
		{
			if ((i != getCurrentPosition().row && j != int(getCurrentPosition().col)) && (abs(i - getCurrentPosition().row) == abs(j - int(getCurrentPosition().col))))
			{
				squares.push_back(Square(char(j)), i));
			}
		}
	}
	return squares;
}

bool Queen::isValidMove()
{

}

void Queen::move(const Square& pos)
{

}