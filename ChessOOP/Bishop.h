#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop();
	~Bishop();
	vector<Square> getValidMoves();
	bool isValidMove() = 0;
	void move(const Square& pos);
};