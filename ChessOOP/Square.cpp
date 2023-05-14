#include "Square.h"
#include "Piece.h"
Square::Square()
{
}

Square::Square(char _column, int _row, sf::Vector2f _center)
{
    this->column=_column;
    this->row=_row;
    this->center=_center;
}
Square::~Square()
{
}
