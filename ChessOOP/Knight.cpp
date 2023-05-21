#include "Knight.h"

Knight::Knight(char name): Piece(name)
{
	if (name == 'N') img.loadFromFile("Image/wN.png");
	else img.loadFromFile("Image/bN.png");

	sprite.setTexture(img);
}

Knight::~Knight()
{

}

vector<Square*> Knight::getValidMoves()
{
	vector<Square*> squares;
	char curCol = getCurrentPosition()->column;
	int curRow = getCurrentPosition()->row;
	for (int i = -2; i <= 2; i++)
	{
		if (i == 0) continue;
		int chg = i;
		if (i < 0) chg = -3 - i;
		else chg = 3 - i;
		if (curCol + i >= 'a' && curCol + i <= 'h')
		{
			if (curRow + chg > 0 && curRow + chg < 9)
				squares.push_back(new Square(curCol + i, curRow + chg));
			if (curRow + chg > 0 && curRow + chg < 9)
				squares.push_back(new Square(curCol + i, curRow - chg));
		}
	}
	return squares;
}

bool Knight::isValidMove()
{
	return 0;
}

