#include "Board.h"

int Board::getSqrIdx(char col, int row) {
	return (row - 1) * 8 + (col - 'a');
}

void Board::initBoard() {
	for (int row = 1; row <= 8; row++) {
		for (char col = 'a'; col <= 'h'; col++) {
			squares.push_back(new Square(col, row));
		}
	}
	//string row1 = "RNBQKBNR";
	squares[getSqrIdx('d', 1)]->piece = new Queen('Q');
	squares[getSqrIdx('d', 8)]->piece = new Queen('q');
}

Board::Board() {
	boardTxt.loadFromFile("Image/CBoard.png");
	board.setTexture(boardTxt);
	board.setPosition(40, 40);
}

Board::~Board() {
	for (int i = 0; i < squares.size(); i++) {
		delete squares[i];
	}
}

void Board::render(sf::RenderWindow*& window) {
	window->draw(board);
	for (int i = 0; i < squares.size(); i++) {
		squares[i]->render(window);
	}
}