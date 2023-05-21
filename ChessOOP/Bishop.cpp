#include "Bishop.h"

Bishop::Bishop(char name): Piece(name)
{
	if (name == 'B') img.loadFromFile("Image/wB.png");
	else img.loadFromFile("Image/bB.png");
	sprite.setTexture(img);
}

Bishop::~Bishop()
{

}

vector<Square*> Bishop::getValidMoves()
{
	vector<Square*> squares;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 'a'; j <= 'h'; j++)
		{
			if ((i != position->row && j != int(position->column)) && (abs(i - position->row) == abs(j - int(position->column))))
			{
				squares.push_back(new Square(j, i));
			}
		}
	}
	return squares;
}

bool Bishop::isValidMove() {
	return 0;
}
