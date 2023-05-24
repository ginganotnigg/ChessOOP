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

vector<Square*> Queen::getValidMoves(vector<Square*> boardSquares)
{
	vector<Square*> squares;
	int row = position->row;
	char col = position->column;
	// Rook moves
	//tren
	for (int i = row + 1; i <= 8; i++) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)])) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (!checkAlly(boardSquares[getSqrIdx(col, i)])) break;
	}
	//duoi
	for (int i = position->row - 1; i >= 0; i--) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)])) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (!checkAlly(boardSquares[getSqrIdx(col, i)])) break;
	}
	//phai
	for (char j = position->column + 1; j <= 'h'; j++) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)])) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (!checkAlly(boardSquares[getSqrIdx(j, row)])) break;
	}
	//trai
	for (char j = position->column - 1; j >= 'a'; j--) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)])) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (!checkAlly(boardSquares[getSqrIdx(j, row)])) break;
	}
	

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
	while (col - chg >= 'a' && row - chg >= 0)
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

bool Queen::isValidMove()
{
	return 0;
}
