#pragma once
#include "Piece.h"
#include "Square.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(char _symbol);
	~Pawn();
	vector<Square*> getValidMoves(vector<Square*> boardSquares);
	bool isValidMove();
};
