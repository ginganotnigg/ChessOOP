#include "Bishop.h"

Bishop::Bishop()
{
	if (name = 'B') img.loadFromFile("Image/wB.png");
	else img.loadFromFile("Image/bB.png");
	sprite.setTexture(img);
}

Bishop::~Bishop()
{

}

vector<Square> Bishop::getValidMoves()
{
	vector<Square> squares;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = int('a'); j <= int('h'); j++)
		{
			if ((i != position.row && j != int(position.col)) && (abs(i - position.row) == abs(j - int(position.col))))
			{
				squares.push_back(Square(char(j)), i));
			}
		}
	}
	return squares;
}


void Bishop::move(const Square& pos)
{

}