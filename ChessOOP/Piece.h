#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Board.h"

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
	void setStatus(const char& status);

	Square* getCurrentPosition();
	string getStatus();
	char getName();
	virtual vector<Square*> getValidMoves(Board &board) = 0;
	virtual bool isValidMove() = 0;
	void move(Square* pos);
	bool checkAlly(Square *s);

	sf::Sprite sprite;
	sf::Vector2f imageSize;
};
