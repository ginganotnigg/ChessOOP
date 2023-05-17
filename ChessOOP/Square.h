#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
struct Point
{
	int x;
	int y;
};

class Square
{
public:
	Square();
	Square(char _collumn, int _row, sf::Vector2f _center);
	~Square();
	Point getCenter(char col, int row);
	sf::Vector2f center;
	char collumn;
	int row;
	Piece* piece;
};
