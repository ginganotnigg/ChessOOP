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
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 0) break;
	}
	//duoi
	for (int i = row - 1; i >= 1; i--) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 0) break;
	}
	//phai
	for (char j = col + 1; j <= 'h'; j++) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 0) break;
	}
	//trai
	for (char j = col - 1; j >= 'a'; j--) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 0) break;
	}


	// Bishop moves
	//tren trai
	int chg = 1;
	while (col - chg >= 'a' && row + chg <= 8)
	{
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row + chg)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col - chg, row + chg)]);
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row + chg)]) == 0) break;
		chg++;
	}

	//duoi trai
	chg = 1;
	while (col - chg >= 'a' && row - chg >= 1)
	{
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row - chg)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col - chg, row - chg)]);
		if (checkAlly(boardSquares[getSqrIdx(col - chg, row - chg)]) == 0) break;
		chg++;
	}

	//tren phai
	chg = 1;
	while (col + chg <= 'h' && row + chg <= 8)
	{
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row + chg)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col + chg, row + chg)]);
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row + chg)]) == 0) break;
		chg++;
	}

	//duoi phai
	chg = 1;
	while (col + chg <= 'h' && row - chg >= 1)
	{
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row - chg)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col + chg, row - chg)]);
		if (checkAlly(boardSquares[getSqrIdx(col + chg, row - chg)]) == 0) break;
		chg++;
	}

	return squares;
}