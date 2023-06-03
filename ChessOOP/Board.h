#pragma once
#include "Square.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include <vector>
#include <string>

class Board {
public:
	sf::Texture boardTxt;
	sf::Sprite board;
	vector<Square*> squares;
	vector<Piece*> pieces;
	vector<string> allStates;
	string from_move;
	vector<string> allStatus;
	string initState;
	string initStatus;
	char namePromote;
	bool isPromote;
	sf::RectangleShape promBox;
	sf::Texture promTxt[4];
	sf::Sprite prom[4];

	// Initialize
	void setPiece(char col, int row, Piece* piece);
	void initPromote();
	void initBoard();
	Board();
	~Board();
	void createPieces(string& state, string& status);
	string getRowState(char& row);
	void loadLastState();
	void loadState(const int& idx);
	void addCurrentState(string& move);
	void addCurrentStatus(string& move);

	// Board function
	bool whiteTurn();
	Square* getOwnKing(bool isWhite);
	bool kingInCheck(Square*& king);
	void checkAlert();
	void moveOrCapture(Square*& from, Square*& to);


	void promotePawn(Square*& to);
	void movePiece(string& move);
	void undoMove();
	bool checkMovePermit(string& move);
	vector<Square*> permitMove(string& from);

	// Update and render
	void targetEvents(sf::Event& e, sf::Vector2f& mouse);
	void moveEvents(sf::Event& e, sf::Vector2f& mouse);
	void update(sf::Event& e, sf::Vector2f& mouse);
	void render(sf::RenderWindow*& window);
};
