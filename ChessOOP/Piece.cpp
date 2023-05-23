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

bool Piece::checkAlly(Square* s) {
	if (name >= 'A' && name < 'Z' && s->piece->name >= 'A' && s->piece->name <= 'Z') {
		return true;
	}
	if (name >= 'a' && name <= 'z' && s->piece->name >= 'a' && s->piece->name <= 'z') {
		return true;
	}
	return false;
}
void Piece::move(Square* des) {
	position = des;
}
