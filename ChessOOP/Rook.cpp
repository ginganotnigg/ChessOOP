#include"Rook.h"
#include"Square.h"
#include <SFML/Graphics.hpp>

Rook::Rook(const char name): Piece(name) {
	if (name == 'R') img.loadFromFile("Image/wR.png");
	else img.loadFromFile("Image/bR.png");
	//imageSize = img.getSize();
	sprite.setTexture(img);

}


vector<Square*> Rook::getValidMoves(vector<Square*> boardSquares) {
	vector<Square*> squares;
	int row = position->row;
	char col = position->column;
	// Rook moves
	// duyet tren
	for (int i = row + 1; i <= 8; i++) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)])) {
			break;
		}
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (!checkAlly(boardSquares[getSqrIdx(col, i)])) {
			break;
		}
	}
	//duyet duoi
	for (int i = position->row - 1; i >= 0; i--) {
		if (checkAlly(boardSquares[getSqrIdx(col, i)])) {
			break;
		}
		squares.push_back(boardSquares[getSqrIdx(col, i)]);
		if (!checkAlly(boardSquares[getSqrIdx(col, i)])) {
			break;
		}
	}
	//duyet phai
	for (char j= position->column + 1; j <= 'h';j++) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)])) {
			break;
		}
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (!checkAlly(boardSquares[getSqrIdx(j, row)])) {
			break;
		}
	}
	//duyet trai
	for (char j = position->column - 1; j >= 'a'; j--) {
		if (checkAlly(boardSquares[getSqrIdx(j, row)])) {
			break;
		}
		squares.push_back(boardSquares[getSqrIdx(j, row)]);
		if (!checkAlly(boardSquares[getSqrIdx(j, row)])) {
			break;
		}
	}
	return squares;
}


