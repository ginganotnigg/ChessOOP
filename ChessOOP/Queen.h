#pragma once
#include "Piece.h"
class Queen: public Piece
{
public:
	Queen();
	~Queen();
	vector<Square> getValidMoves();
	bool isValidMove() = 0;
	void move(const Square& pos);
};