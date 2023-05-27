#pragma once
#include "Piece.h"
#include "Board.h"

class King : public Piece {
public:

	King(char name);

	bool isValidMove();
	vector<Square*> getValidMoves(vector<Square*> boardSquares);

	bool checkCastle(vector<Square*> boardSquares, const char& rColumn, const int& rRow);
	void castle(Square* rook);
};