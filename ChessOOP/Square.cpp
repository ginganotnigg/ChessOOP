#include "Square.h"
#include "Piece.h"
#include <iostream>
using namespace std;

Square::Square()
{
    piece = nullptr;
}

Square::Square(char col, int row)
{
    this->column = col;
    this->row = row;
}

Square::~Square()
{
    delete piece;
}

sf::Vector2f Square::getCenter(char col, int row)
{
    int xPos = 0, yPos = 0;
    for (char i = 'a'; i <= col; i++)
    {
        xPos += 80;
    }
    for (int i = 8; i >= row; i--)
    {
        yPos += 80;
    }
    xPos -= pieceSize.x / 2;
    yPos -= pieceSize.x / 2;
    return sf::Vector2f(xPos, yPos);
}

void Square::render(sf::RenderWindow*& window) {
    if (piece == nullptr) {
        return;
    }
    piece->sprite.setPosition(getCenter(column, row));
    window->draw(piece->sprite);
}
