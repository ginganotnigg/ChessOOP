#include "Pawn.h"
#include <cmath>

Pawn::Pawn(char name) : Piece(name)
{
	if (name == 'P') img.loadFromFile("Image/wP.png");
	else img.loadFromFile("Image/bP.png");

	sprite.setTexture(img);
}

Pawn::~Pawn()
{
}

vector<Square*> Pawn::getValidMoves(vector<Square*> boardSquares)
{
	vector<Square*> squares;
	int row = position->row;
	char col = position->column;
	int dy = (name < 91) ? 1 : -1;
	if (checkAlly(boardSquares[getSqrIdx(col, row + dy * 1)]) == -1)
	{
		squares.push_back(boardSquares[getSqrIdx(col, row + dy * 1)]);
	}

	if (getStatus() == 'u' &&
		checkAlly(boardSquares[getSqrIdx(col, row + dy * 1)]) == -1 &&
		checkAlly(boardSquares[getSqrIdx(col, row + dy * 2)]) == -1
		)
	{
		squares.push_back(boardSquares[getSqrIdx(col, row + dy * 2)]);
	}

	if (col - 1 >= 'a' && col - 1 <= 'h' && checkAlly(boardSquares[getSqrIdx(col - 1, row + dy * 1)]) == 0)

	{
		squares.push_back(boardSquares[getSqrIdx(col - 1, row + dy * 1)]);
	}

	if (col + 1 >= 'a' && col + 1 <= 'h' && checkAlly(boardSquares[getSqrIdx(col + 1, row + dy * 1)]) == 0)
	{
		squares.push_back(boardSquares[getSqrIdx(col + 1, row + dy * 1)]);
	}

	if (checkAlly(boardSquares[getSqrIdx(col - 1, row)]) == 0 &&
		boardSquares[getSqrIdx(col - 1, row)]->piece->getStatus() == 'e')
	{
		squares.push_back(boardSquares[getSqrIdx(col - 1, row + dy * 1)]);
	}

	if (checkAlly(boardSquares[getSqrIdx(col + 1, row)]) == 0 &&
		boardSquares[getSqrIdx(col + 1, row)]->piece->getStatus() == 'e')
	{
		squares.push_back(boardSquares[getSqrIdx(col + 1, row + dy * 1)]);
	}

	return squares;
}
