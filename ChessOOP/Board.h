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
	string initState = "RNBQKBNRPPPPPPPP********************************pppppppprnbqkbnr";
	vector<string> allStatus;
	string initStatus = "uuuuuuuuuuuuuuuu********************************uuuuuuuuuuuuuuuu";
	char namePromote;
	char isPromote;

	void setPiece(char col, int row, Piece* piece);
	void initBoard();
	Board();
	~Board();
	void createPieces(string& state, string& status);
	void clickEvents(sf::Event& e, sf::Vector2f& mouse);
	void moveEvents(sf::Event& e, sf::Vector2f& mouse);
	void checkEvents();
	void update(sf::Event& e, sf::Vector2f& mouse);
	void render(sf::RenderWindow*& window);
	void moveOrCapture(Square*& from, Square*& to);
	void promotePawn(Square* to);
	void movePiece(string& move);
	void addCurrentState(string& move);
	void addCurrentStatus(string& move);
	void loadLastState();
	string getRowState(char& row);
	void undoPiece();
	vector<Square*> permitMove(string& from);
	bool checkMovePermit(string& move);
	bool whiteTurn();
	Square* getOwnKing(bool isWhite);
	bool kingInCheck();
};