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

	squares[getSqrIdx('a', 1)]->piece = new Rook('R');
	squares[getSqrIdx('a', 8)]->piece = new Rook('r');
	squares[getSqrIdx('h', 1)]->piece = new Rook('R');
	squares[getSqrIdx('h', 8)]->piece = new Rook('r');

	squares[getSqrIdx('e', 1)]->piece = new King('K');
	squares[getSqrIdx('e', 8)]->piece = new King('k');

	squares[getSqrIdx('b', 1)]->piece = new Knight('N');
	squares[getSqrIdx('g', 1)]->piece = new Knight('N');
	squares[getSqrIdx('b', 8)]->piece = new Knight('n');
	squares[getSqrIdx('g', 8)]->piece = new Knight('n');

	squares[getSqrIdx('c', 1)]->piece = new Bishop('B');
	squares[getSqrIdx('f', 1)]->piece = new Bishop('B');
	squares[getSqrIdx('c', 8)]->piece = new Bishop('b');
	squares[getSqrIdx('f', 8)]->piece = new Bishop('b');
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
