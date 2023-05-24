#include "Knight.h"

Knight::Knight(char name) : Piece(name)
{
	if (name == 'N') img.loadFromFile("Image/wN.png");
	else img.loadFromFile("Image/bN.png");

	sprite.setTexture(img);
}

Knight::~Knight()
{

}

vector<Square*> Knight::getValidMoves(vector<Square*> boardSquares)
{
	vector<Square*> squares;
	char col = position->column;
	int row = position->row;
	for (int i = -2; i <= 2; i++)
	{
		if (i == 0) continue;
		int chg = i;
		if (i < 0) chg = -3 - i;
		else chg = 3 - i;
		if (col + i >= 'a' && col + i <= 'h')
		{
			if (row + chg > 0 && row + chg < 9 && !checkAlly(boardSquares[getSqrIdx(col + i, row + chg)]))
				squares.push_back(boardSquares[getSqrIdx(col + i, row + chg)]);
			if (row + chg > 0 && row + chg < 9 && !checkAlly(boardSquares[getSqrIdx(col + i, row - chg)]))
				squares.push_back(boardSquares[getSqrIdx(col + i, row - chg)]);
		}
	}

	return squares;
}

bool Knight::isValidMove()
{
	return 0;
}
