#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"

using namespace std;

class Piece {
protected:
	char name;
	Square* position;
	string status;
	sf::Texture img;

public:
	Piece();
	Piece(const char& name);
	~Piece();

	void setName(const char& name);
	void setCurrentPosition(Square* position);
	void setStatus(const string& status);

	Square* getCurrentPosition();
	string getStatus();
	char getName();
	virtual vector<Square*> getValidMoves(vector<Square*> boardSquares) = 0;
	bool checkAlly(Square* s);

	int getSqrIdx(char col, int row);

	sf::Sprite sprite;
	sf::Vector2f imageSize;
};
