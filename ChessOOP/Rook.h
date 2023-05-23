#pragma once
#include"Piece.h"

class Rook : public Piece {
public:

	Rook(char name);

	vector<Square*> getValidMoves(vector<Square*> boardSquares);
};
