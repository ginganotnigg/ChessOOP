#pragma once
#include"Piece.h"

class King : public Piece {
public:

	King(char name);

	vector<Square*> getValidMoves(vector<Square*> boardSquares);

	bool checkCastle(vector<Square*> middles, Square* rook);
	void castle(Square* rook);
};
