#include"Piece.h"

void Piece::setName(const char& name) {
	this->name = name;
}
void Piece::setColor(const string& color) {
	this->color = color;
}
void Piece::setCurrentPosition(const Square& position) {
	this->position = position;
}
void Piece::setStatus(const char& status) {
	this->status = status;
}


Square Piece::getCurrentPosition() {
	return position;
}
char Piece::getStatus() {
	return status;
}
string Piece::getColor() {
	return color;
}
char Piece::getName() {
	return name;
}
