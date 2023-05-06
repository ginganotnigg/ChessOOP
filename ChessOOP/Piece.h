#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include "Square.h"

using namespace std;

class Piece {
protected:
	char   name;
	string color;
	Square position;
	char   status;
public:
	void setName(const char& name);
	void setColor(const string& color);
	void setCurrentPosition(const Square& position);
	void setStatus(const char& status);

	Square getCurrentPosition();
	char   getStatus();
	string getColor();
	char   getName();
	virtual vector<Square> getValidMoves() = 0;
	virtual bool isValidMove() = 0;
	virtual void move(const Square& pos) = 0;
};


