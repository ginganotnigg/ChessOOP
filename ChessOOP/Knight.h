#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight();
	~Knight();
	vector<Square> getValidMoves();
	bool isValidMove() = 0;
	void move(const Square& pos);
};