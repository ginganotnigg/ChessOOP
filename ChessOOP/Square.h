#pragma once
#include <SFML/Graphics.hpp>
class Piece;

class Square
{
public:
	Square();
	Square(char _column, int _row, sf::Vector2f _center);
	~Square();
	sf::Vector2f center;
	char column;
	int row;
	Piece* piece;
};
