#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

class Piece;

class Square
{
public:
	char column;
	int row;
	Piece* piece;
	sf::RectangleShape area;

	Square(char col, int row);
	~Square();
	sf::Vector2f getSqrPos();
	sf::Vector2f getPiecePos();
	void drawValidMove();
	void drawCheck();
	void render(sf::RenderWindow*& window);
};	