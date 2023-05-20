#pragma once
#include "Square.h"
#include "Piece.h"
#include "Queen.h"
#include <vector>
#include <string>

class Board {
public:
	sf::Texture boardTxt;
	sf::Sprite board;
	vector<Square*> squares;
	int getSqrIdx(char col, int row);
	void initBoard();
	Board();
	~Board();
	void render(sf::RenderWindow*& window);
};