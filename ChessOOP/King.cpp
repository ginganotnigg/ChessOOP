#include"King.h"
#include"Square.h"
#include <cmath>
#include <SFML/Graphics.hpp>

King::King(const char name) : Piece(name) {
	if (name == 'K') img.loadFromFile("Image/wK.png");
	else img.loadFromFile("Image/bK.png");
	//imageSize = img.getSize();
	sprite.setTexture(img);

}


vector<Square*> King::getValidMoves(vector<Square*> boardSquares) {
	vector<Square*> squares;
	char col = position->column;
	int row = position->row;

	for (char i = max((int)col - 1, (int)'a'); i <= min((int)col + 1, (int)'h'); i++) {
		for (int j = max(row - 1, 1); j <= min(row + 1, 8); j++) {
			if (i == col && j == row)
				continue;
			if (checkAlly(boardSquares[getSqrIdx(i, j)]))
				continue;
			squares.push_back(boardSquares[getSqrIdx(i, j)]);
		}
	}
	
	return squares;
}

bool King::checkCastle(vector<Square*> middles, Square* rook) {
	if (status != "unmove" || rook->piece->getStatus() != "unmove") {
		return false;
	}
	for (int i = 0; i < middles.size(); i++) {
		if (middles[i]->piece == nullptr) {
			return false;
		}
	}
	return true;
}

void King::castle(Square* rook) {
	if (rook->column == 'a') {
		position->column = 'd';
		rook->column = 'c';
	}
	else if (rook->column == 'h') {
		position->column = 'g';
		rook->column = 'f';
	}
}
