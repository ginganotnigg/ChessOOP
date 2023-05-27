#pragma once
#include "Piece.h"

class Rook : public Piece {
public:

	Rook(char name);
	bool isValidMove();
	vector<Square*> getValidMoves(vector<Square*> boardSquares);
};