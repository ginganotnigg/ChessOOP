#include "Knight.h"

Knight::Knight()
{
	if (name = 'N') img.loadFromFile("Image/wN.png");
	else img.loadFromFile("Image/bN.png");

	sprite.setTexture(img);
}

Knight::~Knight()
{

}

vector<Square> Knight::getValidMoves()
{
	vector<Square> squares;
	for (int i = -2; i <= 2; i++)
	{
		if (i == 0) continue;
		int chg = i;
		if (i < 0) chg = -3 - i;
		else chg = 3 - i;
		if (int(getCurrentPosition().col) + i > 0 && int(getCurrentPosition().col) + i < 9)
		{
			if (getCurrentPosition().row + chg > 0 && getCurrentPosition().row + chg < 9) 
				squares.push_back({ char(int(getCurrentPosition().col) + i), getCurrentPosition().row + chg });
			if (getCurrentPosition().row - chg > 0 && getCurrentPosition().row - chg < 9) 
				squares.push_back({ char(int(getCurrentPosition().col) + i), getCurrentPosition().row - chg });
		}
	}
	return squares;
}

bool Knight::isValidMove()
{

}

void Knight+::move(const Square& pos)
{

}