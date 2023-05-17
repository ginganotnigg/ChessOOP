#include "Square.h"
#include "Piece.h"
#include <iostream>
using namespace std;
Square::Square()
{
}

Square::Square(char _collumn, int _row, sf::Vector2f _center)
{
    this->collumn = _collumn;
    this->row = _row;
    this->center = _center;
}
Square::~Square()
{
}
Point Square::getCenter(char col, int row)
{
    Point center;
    center.x = 0;
    center.y = 0;
    for (char i = 'A'; i <= 'H'; i++)
    {
        center.x += 80;
        if (i == col)
        {
            break;
        }
    }
    for (int i = 8; i > 0; i--)
    {
        center.y += 80;
        if (i == row)
        {
            break;
        }
    }
    center.x -= 30;
    center.y -= 30;
    return center;
}