#include "Knight.h"

Knight::Knight(char name) : Piece(name)
{
	if (name == 'N') img.loadFromFile("Image/wN.png");
	else img.loadFromFile("Image/bN.png");

	sprite.setTexture(img);
}

Knight::~Knight()
{

}

vector<Square*> Knight::getValidMoves(vector<Square*> boardSquares)
{
	vector<Square*> squares;
	int dx[4] = { -1, -2, 1, 2 };
	int dy[4] = { -1, -2, 1, 2 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((j - i) % 2 == 0) {
				continue;
			}
			int newRow = position->row + dx[i];
			char newCol = position->column + dy[j];
			if (newRow < 1 || newRow > 8 || newCol < 'a' || newCol > 'h') {
				continue;
			}
			if (checkAlly(boardSquares[getSqrIdx(newCol, newRow)]) == 1) {
				continue;
			}
			squares.push_back(boardSquares[getSqrIdx(newCol, newRow)]);
		}
	}
	return squares;
}

bool Knight::isValidMove()
{
	return 0;
}