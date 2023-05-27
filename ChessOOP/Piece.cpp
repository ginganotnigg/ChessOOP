#include "Piece.h"

Piece::Piece() {
	name = ' ';
	position = nullptr;
	status = 'u';		// unmove/move/pinned/checked/enpassant/*
}

Piece::Piece(const char& name) {
	this->name = name;
	this->position = nullptr;
	this->status = 'u';
}


Piece::~Piece() {
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

char Piece::getStatus() {
	return status;
}

char Piece::getName() {
	return name;
}

bool Piece::isWhite() {
	return (name >= 'A' && name <= 'Z');
}

int Piece::checkAlly(Square* s) {
	if (s->piece == nullptr) {
		return -1;
	}
	if (isWhite() == s->piece->isWhite()) {
		return 1;
	}
	return 0;
}

int getSqrIdx(char col, int row) {
	return (row - 1) * 8 + (col - 'a');
}