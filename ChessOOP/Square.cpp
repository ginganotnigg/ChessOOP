#include "Square.h"
#include "Piece.h"
Square::Square()
{
}

Square::Square(char _collumn, int _row, sf::Vector2f _center)
{
    this->collumn=_collumn;
    this->row=_row;
    this->center=_center;
}
Square::~Square()
{
}