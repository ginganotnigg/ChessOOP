#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"

using namespace std;

class Piece {
protected:
	char name;
	char status;
	sf::Texture img;

public:
	Square* position;
	sf::Sprite sprite;

	Piece();
	Piece(const char& name);
	virtual ~Piece();

	void setName(const char& name);
	void setCurrentPosition(Square* position);
	void setStatus(const char& status);

	Square* getCurrentPosition();
	char getStatus();
	char getName();

	bool isWhite();
	int checkAlly(Square* s);
	virtual vector<Square*> getValidMoves(vector<Square*> boardSquares) = 0;
};

int getSqrIdx(char col, int row);
