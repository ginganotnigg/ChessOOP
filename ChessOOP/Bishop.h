#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(char name);
	~Bishop();
	vector<Square*> getValidMoves();
	bool isValidMove();
};
