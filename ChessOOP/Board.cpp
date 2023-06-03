#include "Board.h"

void Board::setPiece(char col, int row, Piece* piece) {
	piece->position = squares[getSqrIdx(col, row)];
	squares[getSqrIdx(col, row)]->piece = piece;
	pieces.push_back(piece);
}

void Board::initBoard() {
	//initState = "RNBQKBNRPPPPPPPP********************************pppppppprnbqkbnr";
	//initStatus = "uuuuuuuuuuuuuuuu********************************uuuuuuuuuuuuuuuu";
	// Stalemate
	//initState = "********************************************KQ****************k*";
	//initStatus = "********************************************mm****************m*";
	// Insufficience
	initState = "***************************************n***pKB*********k********";
	initStatus = "***************************************m***mmm*********m********";
	// 50-move rule
	//initState = "*******************PK******P*PN****pPp******p********kb*********";
	//initStatus = "*******************mm******m*mm****mmm******m********mm*********";
	//moves_since_capture = 47;
	// Checkmate
	//initState = "**********n********R*********************K***************k******";
	//initStatus = "**********m********m*********************m***************m******";
	// Promote
	//initState = "RNBQKBNRPPPPPPP********************************Ppppppppprnbqkbnr";
	//initStatus = "uuuuuuuuuuuuuuu********************************uuuuuuuuuuuuuuuuu";
	// Castle
	//initState = "RNBQK**RPPPPPPPP********************************ppppppppr***kbnr";
	//initStatus = "uuuuu**uuuuuuuuu********************************uuuuuuuuu***uuuu";
	moves_since_capture = 0;
	namePromote = ' ';
	isPromote = false;

	for (int row = 1; row <= 8; row++) {
		for (char col = 'a'; col <= 'h'; col++) {
			squares.push_back(new Square(col, row));
		}
	}

	allStates.push_back(initState);
	allStatus.push_back(initStatus);
	createPieces(initState, initStatus);
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

void Board::createPieces(string& state, string& status)
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
			squares[sqrIdx]->piece = nullptr;
			sqrIdx++;
			break;
		}
	}
}

bool Board::whiteTurn() {
	return (allStates.size() % 2 != 0);
}

Square* Board::getOwnKing(bool isWhite) {
	char name = (isWhite) ? 'K' : 'k';
	return squares[allStates.back().find(name)];
}

bool Board::kingInCheck(Square*& king) {
	//cout << getOwnKing(whiteTurn())->row << " ";
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->isWhite() != whiteTurn()) {
			vector<Square*> vals = pieces[i]->getValidMoves(squares);
			for (auto j : vals) {
				if (j == king) {
					return true;
				}
			}
		}
	}
	return false;
}

void Board::checkAlert(sf::Sound sound[]) {
	Square* own_king = getOwnKing(whiteTurn());
	if (kingInCheck(own_king)) {
		sound[4].play();
		own_king->drawCheck();
	}
	else {
		if (own_king->area.getFillColor().a != 0) {
			own_king->area.setFillColor(sf::Color(0, 0, 0, 0));
		}
	}
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
	int fromIdx = getSqrIdx(move[0], move[1] - '0');
	lastStatus[fromIdx] = '*';

	int toIdx = getSqrIdx(move[2], move[3] - '0');
	char mov = 'm';
	char enp = 'e';

	lastStatus[toIdx] = 'm';
	//squares[toIdx]->piece->setStatus(mov);

	// En passant situation
	for (int i = 0; i < squares.size(); i++) {
		if ((squares[i]->piece != nullptr) &&
			lastStatus[i] == 'e')
		{
			lastStatus[i] = 'm';
			squares[i]->piece->setStatus(mov);
		}
	}

	if ((squares[toIdx]->piece != nullptr) &&
		(squares[toIdx]->piece->getName() == 'P' || squares[toIdx]->piece->getName() == 'p') &&
		(abs(move[3] - move[1]) == 2))
	{
		lastStatus[toIdx] = 'e';
		//squares[toIdx]->piece->setStatus(enp);
	}

	// Castle situation
	if (squares[toIdx]->piece != nullptr
		&& squares[toIdx]->piece->getName() == 'K') {
		if (move == "e1c1") {
			lastStatus[getSqrIdx('a', 1)] = '*';
			lastStatus[getSqrIdx('d', 1)] = 'm';
			//squares[getSqrIdx('d', 1)]->piece->setStatus(mov);
		}
		else if (move == "e1g1") {
			lastStatus[getSqrIdx('h', 1)] = '*';
			lastStatus[getSqrIdx('f', 1)] = 'm';
			//squares[getSqrIdx('f', 1)]->piece->setStatus(mov);
		}
	}
	if (squares[toIdx]->piece != nullptr
		&& squares[toIdx]->piece->getName() == 'k'
		) {
		if (move == "e8c8") {
			lastStatus[getSqrIdx('a', 8)] = '*';
			lastStatus[getSqrIdx('d', 8)] = 'm';
			//squares[getSqrIdx('d', 1)]->piece->setStatus(mov);
		}
		else if (move == "e8g8") {
			lastStatus[getSqrIdx('h', 8)] = '*';
			lastStatus[getSqrIdx('f', 8)] = 'm';
			//squares[getSqrIdx('f', 1)]->piece->setStatus(mov);
		}
	}
	allStatus.push_back(lastStatus);
}

void Board::loadLastState()
{
	// Delete current board
	for (auto i : pieces) {
		delete i;
		i = nullptr;
	}
	pieces.clear();
	// Load board recently
	string lastState = allStates.back();
	string lastStatus = allStatus.back();
	createPieces(lastState, lastStatus);
}

void Board::loadState(const int& idx)
{
	// Delete current board
	for (auto i : pieces) {
		delete i;
		i = nullptr;
	}
	pieces.clear();
	// Load board recently
	string lastState = allStates[idx];
	string lastStatus = allStates[idx];
	createPieces(lastState, lastStatus);
}

void Board::undoMove()
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
	//En passant
	int dx = abs(to->column - from->column);
	int dy = abs(to->row - from->row);
	if (to->piece == nullptr && squares[getSqrIdx(to->column, from->row)]->piece != nullptr &&
		((from->piece->getName() == 'P' && squares[getSqrIdx(to->column, from->row)]->piece->getName() == 'p') ||
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
	Square* own_king = getOwnKing(whiteTurn());
	Square* from = squares[getSqrIdx(move[0], move[1] - '0')];
	Square* to = squares[getSqrIdx(move[2], move[3] - '0')];

	// Castle situation
	if ((from->piece->getName() == 'K' && move == "e1c1") || (from->piece->getName() == 'K' && move == "e1g1") ||
		(from->piece->getName() == 'k' && move == "e8c8") || (from->piece->getName() == 'k' && move == "e8g8"))
	{
		if (kingInCheck(own_king)) {
			return false;
		}
		for (char i = min((int)move[0], (int)move[2]) + 1; i < max((int)move[0], (int)move[2]); i++) {
			if (kingInCheck(squares[getSqrIdx(i, move[1] - '0')])) {
				return false;
			}
		}
	}

	moveOrCapture(from, to);

	// Ktra neu sau khi di xong, tuong bi bat
	if (to->piece->getName() == 'k' || to->piece->getName() == 'K') {
		if (kingInCheck(to)) {
			loadLastState();
			return false;
		}
		addCurrentState(move);
		addCurrentStatus(move);
		undoMove();
		return true;
	}

	if (kingInCheck(own_king))
	{
		loadLastState();
		return false;
	}
	addCurrentState(move);
	addCurrentStatus(move);
	undoMove();
	return true;
}

vector<Square*> Board::permitMove(string& from)
{
	vector<Square*> validSquare = squares[getSqrIdx(from[0], from[1] - '0')]->piece->getValidMoves(squares);
	vector<Square*> res;
	for (int i = 0; i < validSquare.size(); i++) {
		string move = from + validSquare[i]->column + to_string(validSquare[i]->row);
		if (checkMovePermit(move)) {
			res.push_back(validSquare[i]);
		}
	}
	return res;
}

void Board::promotePawn(Square*& to)
{
	char namePawn = to->piece->getName();
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i] == to->piece)
		{
			pieces.erase(pieces.begin() + i);
			break;
		}
	}
	delete to->piece;
	to->piece = nullptr;
	Piece* promote = nullptr;
	switch (namePromote)
	{
	case 'r':
		promote = (namePawn == 'p') ? new Rook('r') : new Rook('R');
		break;
	case 'b':
		promote = (namePawn == 'p') ? new Bishop('b') : new Bishop('B');
		break;
	case 'n':
		promote = (namePawn == 'p') ? new Knight('n') : new Knight('N');
		break;
	case 'q':
		promote = (namePawn == 'p') ? new Queen('q') : new Queen('Q');
		break;
	}
	to->piece = promote;
	promote->position = to;
	pieces.push_back(promote);
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
	// Promote Pawn to Queen/Rook/Bishop/Knight if necessary
	if (to->piece != nullptr && (to->piece->getName() == 'P' && to->row == 8) || (to->piece->getName() == 'p' && to->row == 1))
	{
		promotePawn(to);
	}
	// Add state to next turn
	addCurrentState(move);
	addCurrentStatus(move);
}

bool Board::canMove(bool isWhite)
{
	for (char i = 'a'; i <= 'h'; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if (squares[getSqrIdx(i, j)]->piece != nullptr && squares[getSqrIdx(i, j)]->piece->isWhite() == isWhite) {
				string from = i + to_string(j);
				if (permitMove(from).size() > 0) {
					return true;
				}
			}
		}
	}
	return false;
}

char Board::checkGameover()
{
	//Fifty move rule
	if (moves_since_capture >= 50) return 'f';

	//Checking insufficient material
	if (pieces.size() < 3) return 'i';
	if (pieces.size() < 4)
	{
		std::string symbols;
		for (auto i : pieces) symbols.push_back(i->getName());
		if (symbols.find('R') == -1 && symbols.find('r') == -1 &&
			symbols.find('Q') == -1 && symbols.find('q') == -1 &&
			symbols.find('P') == -1 && symbols.find('p') == -1)
			return 'i';
	}
	if (pieces.size() < 5)
	{
		std::string symbols;
		for (auto i : pieces) symbols.push_back(i->getName());
		if (symbols.find('b') != -1 && symbols.find('B') != -1 ||
			symbols.find('b') != -1 && symbols.find('N') != -1 ||
			symbols.find('n') != -1 && symbols.find('B') != -1 ||
			symbols.find('n') != -1 && symbols.find('N') != -1)
			return 'i';
	}

	// Mate
	Square* own_king = getOwnKing(whiteTurn());
	if (kingInCheck(own_king) && !canMove(whiteTurn())) return 'c';
	if (!canMove(whiteTurn())) return 's';
	return '*';
}

void Board::targetEvents(sf::Event& e, sf::Vector2f& mouse, sf::Sound sound[]) {
	for (int i = 0; i < pieces.size(); i++) {
		if (e.key.code == sf::Mouse::Left && pieces[i]->sprite.getGlobalBounds().contains(mouse)
			&& pieces[i]->isWhite() == whiteTurn()) {
			switch (e.type) {

			case e.MouseButtonPressed: {
				for (auto i : squares) {
					i->area.setFillColor(sf::Color(0, 0, 0, 0));
				}
				sound[1].play();
				break;
			}

			case e.MouseButtonReleased: {
				from_move = pieces[i]->position->column + to_string(pieces[i]->position->row);
				vector<Square*> pers = permitMove(from_move);
				for (int j = 0; j < pers.size(); j++) {
					pers[j]->drawValidMove();
				}
				i = pieces.size();
				if (squares[getSqrIdx(from_move[0], from_move[1] - '0')]->piece != nullptr &&
					((squares[getSqrIdx(from_move[0], from_move[1] - '0')]->piece->getName() == 'P' && from_move[1] == '7') ||
						(squares[getSqrIdx(from_move[0], from_move[1] - '0')]->piece->getName() == 'p' && from_move[1] == '2')))
				{
					isPromote = true;
				}
				else {
					isPromote = false;
				}
				break;
			}
			}
		}
	}
}

void Board::moveEvents(sf::Event& e, sf::Vector2f& mouse, sf::Sound sound[]) {
	if (isPromote) {
		return;
	}
	for (int i = 0; i < squares.size(); i++) {
		string move;
		string to_move;
		if (e.key.code == sf::Mouse::Left && squares[i]->area.getGlobalBounds().contains(mouse)
			&& squares[i]->area.getFillColor().a != 0) {
			switch (e.type) {

			case e.MouseButtonReleased: {
				Square* to = squares[getSqrIdx(squares[i]->column, squares[i]->row)];
				to_move = to->column + to_string(to->row);
				if (from_move == to_move) {
					break;
				}
				move = from_move + to_move;
				int last_size = pieces.size();
				movePiece(move);
				i = squares.size();
				loadLastState();
				if (pieces.size() < last_size) {
					moves_since_capture = 0;
					sound[3].play();
				}
				else {
					moves_since_capture++;
					sound[2].play();
				}
				for (auto sqr : squares) { sqr->area.setFillColor(sf::Color(0, 0, 0, 0)); }
				checkAlert(sound);
				break;
			}
			}
		}
	}
}

void Board::update(sf::Event& e, sf::Vector2f& mouse, sf::Sound sound[]) {
	targetEvents(e, mouse, sound);
	moveEvents(e, mouse, sound);
}

void Board::renderPromote(sf::RenderWindow*& window) {
	window->draw(promBox);
	for (int i = 0; i < 4; i++) {
		window->draw(prom[i]);
	}
}

void Board::render(sf::RenderWindow*& window) {
	window->draw(board);
	for (int i = 0; i < squares.size(); i++) {
		squares[i]->render(window);
	}
}