#include "Bishop.h"

Bishop::Bishop(char name) : Piece(name)
{
	if (name == 'B') img.loadFromFile("Image/wB.png");
	else img.loadFromFile("Image/bB.png");
	sprite.setTexture(img);
}

Bishop::~Bishop()
{

}

vector<Square*> Bishop::getValidMoves(vector<Square*> boardSquares)
{
	vector<Square*> squares;
	char col = position->column;
	int row = position->row;

	//bishop move
	//tren trai
	int chg = 1;
	while (col - chg >= 'a' && row + chg <= 8)
	{
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row + chg)])) break;
		squares.push_back(boardSquares[getSqrIdx(col - chg, row + chg)]);
		if (!checkAlly(boardSquares[getSqrIdx(col - chg, row + chg)])) break;
		chg++;
	}

	//duoi trai
	chg = 1;
	while (col - chg >= 'a' && row - chg >= 0 )
	{
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row - chg)])) break;
		squares.push_back(boardSquares[getSqrIdx(col - chg, row - chg)]);
		if (!checkAlly(boardSquares[getSqrIdx(col - chg, row - chg)])) break;
		chg++;
	}

	//tren phai
	chg = 1;
	while (col + chg <= 'h' && row + chg <= 8)
	{
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row + chg)])) break;
		squares.push_back(boardSquares[getSqrIdx(col + chg, row + chg)]);
		if (!checkAlly(boardSquares[getSqrIdx(col + chg, row + chg)])) break;
		chg++;
	}

	//duoi phai
	chg = 1;
	while (col + chg <= 'h' && row - chg >= 0)
	{
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row - chg)])) break;
		squares.push_back(boardSquares[getSqrIdx(col + chg, row - chg)]);
		if (!checkAlly(boardSquares[getSqrIdx(col + chg, row - chg)])) break;
		chg++;
	}

	return squares;
}

bool Bishop::isValidMove() {
	return 0;
}
