#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(char name);
	~Knight();
	vector<Square*> getValidMoves(vector<Square*> boardSquares);
	bool isValidMove();

};
