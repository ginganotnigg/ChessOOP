#pragma once
#include"Piece.h"
#include"Board.h"

class King : public Piece {
public:

	King(char name);

	bool isValidMove();
	vector<Square*> getValidMoves();

	bool checkCastle(vector<Square*> middles, Square* rook);
	void castle(Square* rook);
};
