#include "Piece.h"

Piece::Piece() {
	name = ' ';
	position = nullptr;
	status = "unmove";
}

Piece::Piece(const char& name) {
	this->name = name;
}


Piece::~Piece() {
	delete position;
	position = nullptr;
}


void Piece::setName(const char& name) {
	this->name = name;
}

void Piece::setCurrentPosition(Square* position) {
	this->position = position;
}

void Piece::setStatus(const char& status) {
	this->status = status;
}


Square* Piece::getCurrentPosition() {
	return position;
}

string Piece::getStatus() {
	return status;
}

char Piece::getName() {
	return name;
}

void Piece::move(Square* des) {
	position = des;
}