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
	void clickPiece(sf::Event& e, sf::Vector2f& mouse, vector<Square*> boardSquares);
	void drawValidMove();
	void render(sf::RenderWindow*& window);
};