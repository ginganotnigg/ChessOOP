#include "Square.h"
#include "Piece.h"
#include <iostream>

using namespace std;

Square::Square(char col, int row)
{
    this->column = col;
    this->row = row;
    this->piece = nullptr;
    this->area.setSize(sf::Vector2f(76, 76));
    this->area.setFillColor(sf::Color(0, 0, 0, 0));
}

Square::~Square()
{
}

sf::Vector2f Square::getSqrPos()
{
    int xPos = 40 + 80 * (column - 'a');
    int yPos = 40 + 80 * (8 - row);
    return sf::Vector2f(xPos, yPos);
}

sf::Vector2f Square::getPiecePos()
{
    int xPos = 45 + 80 * (column - 'a');
    int yPos = 45 + 80 * (8 - row);
    return sf::Vector2f(xPos, yPos);
}

void Square::drawValidMove() {
    area.setPosition(getSqrPos().x + 2, getSqrPos().y + 2);
    if (piece != nullptr) {
        area.setFillColor(sf::Color(0, 255, 204, 100));
        return;
    }
    area.setFillColor(sf::Color(102, 204, 255, 100));
}

void Square::drawCheck() {
    area.setPosition(getSqrPos().x + 2, getSqrPos().y + 2);
    area.setFillColor(sf::Color(255, 0, 0, 100));
}

void Square::render(sf::RenderWindow*& window) {
    if (piece != nullptr) {
        piece->sprite.setPosition(getPiecePos());
        window->draw(piece->sprite);
    }
    window->draw(area);
}