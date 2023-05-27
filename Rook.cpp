#include "Rook.h"
#include "Square.h"
#include <SFML/Graphics.hpp>

Rook::Rook(const char name) : Piece(name) {
	if (name == 'R') img.loadFromFile("Image/wR.png");
	else img.loadFromFile("Image/bR.png");
	//imageSize = img.getSize();
	sprite.setTexture(img);

}

bool Rook::isValidMove() {

	return false;

}

vector<Square*> Rook::getValidMoves(vector<Square*> boardSquares) {
	vector<Square*> squares;
	int row = position->row;
	char col = position->column;
	// Rook moves
	//tren
	for (int i = row + 1; i <= 8; i++) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 0) break;
	}
	//duoi
	for (int i = row - 1; i >= 1; i--) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (checkAlly(boardSquares[getSqrIdx(col, i)]) == 0) break;
	}
	//phai
	for (char j = col + 1; j <= 'h'; j++) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 0) break;
	}
	//trai
	for (char j = col - 1; j >= 'a'; j--) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 1) break;
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (checkAlly(boardSquares[getSqrIdx(j, row)]) == 0) break;
	}

	return squares;
}