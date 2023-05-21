#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Piece;

class Square
{
public:
	char column;
	int row;
	Piece* piece;
	sf::Vector2f pieceSize = sf::Vector2f(70, 70);

	Square();
	Square(char col, int row);
	~Square();
	sf::Vector2f getCenter(char col, int row);
	void render(sf::RenderWindow*& window);
};
