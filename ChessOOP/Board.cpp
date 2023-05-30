#include "Board.h"

void Board::setPiece(char col, int row, Piece* piece) {
	piece->position = squares[getSqrIdx(col, row)];
	squares[getSqrIdx(col, row)]->piece = piece;
	pieces.push_back(piece);
}

void Board::initBoard() {
	for (int row = 1; row <= 8; row++) {
		for (char col = 'a'; col <= 'h'; col++) {
			squares.push_back(new Square(col, row));
		}
	}

	allStates.push_back(initState);
	allStatus.push_back(initStatus);
	createPieces(initState,initStatus);
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

void Board::createPieces(string& state,string& status)
{
	int sqrIdx = 0;
	for (int j = 0; j < state.size(); j++)
	{
		char temp = state[j];
		Piece* p = nullptr;
		switch (temp)
		{
		case 'R': case 'r':
			p = new Rook(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case 'N': case 'n':
			p = new Knight(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case 'B': case 'b':
			p = new Bishop(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case 'Q': case 'q':
			p = new Queen(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case 'K': case 'k':
			p = new King(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case 'P': case 'p':
			p = new Pawn(temp);
			p->position = squares[sqrIdx];
			squares[sqrIdx]->piece = p;
			squares[sqrIdx]->piece->setStatus(status[sqrIdx]);
			pieces.push_back(p);
			sqrIdx++;
			break;
		case '*':
			sqrIdx++;
			break;
		}
	}
}

bool kingInCheck()
{
	// from square check tuong bi bat
	return false;
}

string Board::getRowState(char& row)
{
	string rowState = "";
	for (char col = 'a'; col <= 'h'; col++)
	{
		if (squares[getSqrIdx(col, row - '0')]->piece == nullptr)
		{
			rowState += '*';
		}
		else
		{
			rowState.push_back(squares[getSqrIdx(col, row - '0')]->piece->getName());
		}
	}
	return rowState;
}

void Board::addCurrentState(string& move)
{
	string lastState = allStates.back();

	char rowFrom = move[1];
	char rowTo = move[3];

	// rowFrom and rowTo
	for (int i = 0; i < 8; i++) {
		lastState[getSqrIdx(i + 'a', rowFrom - '0')] = getRowState(rowFrom)[i];
		lastState[getSqrIdx(i + 'a', rowTo - '0')] = getRowState(rowTo)[i];
	}

	allStates.push_back(lastState);
}

void Board::addCurrentStatus(string& move) {
	string lastStatus = allStatus.back();
	lastStatus[getSqrIdx(move[0], move[1] - '0')] = '*';
	lastStatus[getSqrIdx(move[2], move[3] - '0')] = 'm';
	char temp = 'm';
	squares[getSqrIdx(move[2], move[3] - '0')]->piece->setStatus(temp);
	if ((squares[getSqrIdx(move[2], move[3] - '0')]->piece != nullptr) &&
		(squares[getSqrIdx(move[2], move[3] - '0')]->piece->getName() == 'P' ||
			squares[getSqrIdx(move[2], move[3] - '0')]->piece->getName() == 'p') &&
		(abs(move[3] - move[1]) == 2))
	{
		lastStatus[getSqrIdx(move[2], move[3] - '0')] = 'e';
		char temp1 = 'e';
		squares[getSqrIdx(move[2], move[3] - '0')]->piece->setStatus(temp1);
	}
	if (squares[getSqrIdx(move[2], move[3] - '0')]->piece != nullptr
		&& squares[getSqrIdx(move[2], move[3] - '0')]->piece->getName() == 'K') {
		if (move == "e1c1") {
			lastStatus[getSqrIdx('a', 1)] = '*';
			lastStatus[getSqrIdx('d', 1)] = 'm';
			squares[getSqrIdx('d',1)]->piece->setStatus(temp);
		}
		else if (move == "e1g1") {
			lastStatus[getSqrIdx('h', 1)] = '*';
			lastStatus[getSqrIdx('f', 1)] = 'm';
			squares[getSqrIdx('f', 1)]->piece->setStatus(temp);
		}
	}
	if (squares[getSqrIdx(move[2], move[3] - '0')]->piece != nullptr
		&&squares[getSqrIdx(move[2], move[3] - '0')]->piece->getName() == 'k'
		) {
		if (move == "e8c8") {
			lastStatus[getSqrIdx('a', 8)] = '*';
			lastStatus[getSqrIdx('d', 8)] = 'm';
			squares[getSqrIdx('d', 1)]->piece->setStatus(temp);
		}
		else if (move == "e8g8") {
			lastStatus[getSqrIdx('h', 8)] = '*';
			lastStatus[getSqrIdx('f', 8)] = 'm';
			squares[getSqrIdx('f', 1)]->piece->setStatus(temp);
		}
	}
	allStatus.push_back(lastStatus);
}

void Board::loadLastState()
{
	// Delete current board
	for (auto i : pieces)
		delete i;
	pieces.clear();
	// Load board recently
	string lastState = allStates.back();
	string lastStatus = allStatus.back();
	createPieces(lastState,lastStatus);
}

void Board::undoPiece()
{
	if (allStates.size() == 1)
	{
		return;
	}
	allStates.pop_back();
	allStatus.pop_back();
	loadLastState();
}

void Board::moveOrCapture(Square*& from, Square*& to) {
	// Capture Piece
	if (to->piece != nullptr && to->piece->isWhite() != from->piece->isWhite())
	{
		// Delete Piece at to
		for (int i = 0; i < pieces.size(); i++)
		{
			if (pieces[i] == to->piece)
			{
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
		delete to->piece;
	}
	//EnPassant
	int dx = abs(to->column - from->column);
	int dy = abs(to->row - from->row);
	if (to->piece == nullptr && squares[getSqrIdx(to->column, from->row)]->piece != nullptr &&
	    ((from->piece->getName() == 'P' && squares[getSqrIdx(to->column, from->row)]->piece->getName() == 'p')||
		 (from->piece->getName() == 'p' && squares[getSqrIdx(to->column, from->row)]->piece->getName() == 'P')) &&
		dx == 1 && dy == 1 &&
		squares[getSqrIdx(to->column, from->row)]->piece->getStatus() == 'e')
	{
		// Delete Piece at squares[getSqrIdx(to->column, from->row)]
		for (int i = 0; i < pieces.size(); i++)
		{
			if (pieces[i] == squares[getSqrIdx(to->column, from->row)]->piece)
			{
				pieces.erase(pieces.begin() + i);
				break;
			}
		}
		delete squares[getSqrIdx(to->column, from->row)]->piece;
		squares[getSqrIdx(to->column, from->row)]->piece = nullptr;
	}
	
	// Move Piece
	to->piece = from->piece;
	from->piece = nullptr;
	to->piece->position = to;
}

bool Board::checkMovePermit(string& move)
{
	// Set from and to
	Square* from = squares[getSqrIdx(move[0], move[1] - '0')];
	Square* to = squares[getSqrIdx(move[2], move[3] - '0')];
	if ((from->piece->getName() == 'K' && move == "e1c1") || (from->piece->getName() == 'K' && move == "e1g1"))
	{
		if (kingInCheck())
		{
			return false;
		}
	}
	if ((from->piece->getName() == 'k' && move == "e8c8") || (from->piece->getName() == 'k' && move == "e8g8"))
	{
		if (kingInCheck())
		{
			return false;
		}
	}

	moveOrCapture(from, to);

	// Ktra neu sau khi di xong, tuong bi bat
	if (kingInCheck())
	{
		loadLastState();
		return false;
	}
	addCurrentState(move);
	addCurrentStatus(move);
	return true;
}

vector<Square*> Board::permitMove(string& from)
{
	Square* sq = squares[getSqrIdx(from[0], from[1] - '0')];
	vector<Square*> validSquare = sq->piece->getValidMoves(squares);
	for (int i = 0; i < validSquare.size(); i++)
	{
		string move = from + validSquare[i]->column + to_string(validSquare[i]->row);
		bool check = checkMovePermit(move);
		if (check)
		{
			undoPiece();
		}
		else
		{
			validSquare.erase(validSquare.begin() + i);
		}
	}
	return validSquare;
}

void Board::movePiece(string& move)
{
	// Set from and to
	Square* from = squares[getSqrIdx(move[0], move[1] - '0')];
	Square* to = squares[getSqrIdx(move[2], move[3] - '0')];

	// Check castle and move rooks if necessary
	int kRow = 0;
	if (from->piece->getName() == 'K') {
		kRow = 1;
	}
	if (from->piece->getName() == 'k') {
		kRow = 8;
	}
	Square* R_from = nullptr;
	Square* R_to = nullptr;
	if (move == "e" + to_string(kRow) + "c" + to_string(kRow))
	{
		R_from = squares[getSqrIdx('a', kRow)];
		R_to = squares[getSqrIdx('d', kRow)];
	}
	else if (move == "e" + to_string(kRow) + "g" + to_string(kRow))
	{
		R_from = squares[getSqrIdx('h', kRow)];
		R_to = squares[getSqrIdx('f', kRow)];
	}
	if (R_from != nullptr && R_to != nullptr)
	{
		moveOrCapture(R_from, R_to);
	}

	// Move or capture
	moveOrCapture(from, to);

	// Promote Pawn to Queen/Rook if necessary
	if ((to->piece->getName() == 'P' && to->row == 8) || (to->piece->getName() == 'p' && to->row == 1))
	{
		
		Piece* promote =  (to->piece->getName() == 'p') ? new Rook('r') : new Rook('R');
		promote->position = to;
		for (int i = 0; i < pieces.size(); i++)
		{
			if (pieces[i] == to->piece)
			{
				pieces.erase(pieces.begin() + i);
			}
		}
		delete to->piece;
		to->piece = promote;
		pieces.push_back(promote);
	}

	// Add state to next turn
	addCurrentState(move);
	addCurrentStatus(move);
	cout << allStatus.back() << endl;
}

void Board::clickEvents(sf::Event& e, sf::Vector2f& mouse) {
	bool whiteTurn = (allStates.size() % 2 != 0);
	for (int i = 0; i < pieces.size(); i++) {
		if (e.key.code == sf::Mouse::Left && pieces[i]->sprite.getGlobalBounds().contains(mouse)
			&& pieces[i]->isWhite() == whiteTurn) {
			switch (e.type) {

			case e.MouseButtonPressed: {
				for (auto i : squares) {
					i->area.setFillColor(sf::Color(0, 0, 0, 0));
				}
				break;
			}

			case e.MouseButtonReleased: {
				from_move = pieces[i]->position->column + to_string(pieces[i]->position->row);
				for (int j = 0; j < pieces[i]->getValidMoves(squares).size(); j++) {
					pieces[i]->getValidMoves(squares)[j]->drawValidMove();
				}
				//vector<Square*> pmm = permitMove(from_move);
				//for (int j = 0; j < pmm.size(); j++) {
				//	pieces[i]->getValidMoves(squares)[j]->drawValidMove();
				//}
				i = pieces.size();
				break;
			}
			}
		}
	}
}

void Board::moveEvents(sf::Event& e, sf::Vector2f& mouse) {
	for (int i = 0; i < squares.size(); i++) {
		string move;
		string to_move;
		if (e.key.code == sf::Mouse::Left && squares[i]->area.getGlobalBounds().contains(mouse)
			&& squares[i]->area.getFillColor().a != 0) {
			switch (e.type) {

			case e.MouseButtonReleased: {
				to_move = squares[i]->column + to_string(squares[i]->row);
				if (from_move == to_move) {
					break;
				}
				move = from_move + to_move;
				cout << move << " ";
				movePiece(move);
				i = squares.size();
				for (auto i : squares) {
					i->area.setFillColor(sf::Color(0, 0, 0, 0));
				}
				break;
			}
			}
		}
	}
}

void Board::update(sf::Event& e, sf::Vector2f& mouse) {
	clickEvents(e, mouse);
	moveEvents(e, mouse);
}

void Board::render(sf::RenderWindow*& window) {
	window->draw(board);
	for (int i = 0; i < squares.size(); i++) {
		squares[i]->render(window);
	}
}
