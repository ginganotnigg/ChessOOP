#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(char name);
	~Queen();
	vector<Square*> getValidMoves(vector<Square*> boardSquares);
	bool isValidMove();
};
