#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include "GUIText.h"
#include "Board.h"

using namespace std;

class Game {
private:
	// Window
	int width = 1080;
	int height = 720;
	sf::RenderWindow* window;
	sf::Event ev;
	sf::ContextSettings settings;

	// Mouse positions
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	// Board & Pieces

	// Sounds
	sf::SoundBuffer soundBf[7];
	sf::Sound sound[7];

	// Texts
	sf::Font font;
	GUIText menuText[5];
	GUIText ingameText[5];
	GUIText replayText[4];
	GUIText endgameText[5];

	// Variables
	int draw_idx;
	bool soundLoop;
	bool replayPaused;
	bool renderProm;
	Board board;

	// Background
	sf::Texture bgrTxt;
	sf::Sprite bgr;
	sf::RectangleShape promBox;
	sf::Texture promTxt[4];
	sf::Sprite prom[4];
	sf::RectangleShape whiteRect;

	// Private funcs
	void initVariables();
	void initWindow();
	void initSound();
	void initFont();
	void initText();
	void initBgr();
	void initBoard();
	void initPromote();

public:
	// Cons & Dest
	Game();
	virtual ~Game();

	// Accessors
	bool running();
	bool getFinish();

	// Updating functions
	void pollEvents();
	void updateText();
	void updateMousePos();
	void clickPieces();
	void capturePieces();
	void movePieces();
	void checkmatePieces();
	void update();

	// Rendering functions
	void renderBoard();
	void renderBgr();
	void renderMenu();
	void renderIngame();
	void renderReplay();
	void renderEndgame();
	void renderPromote();
	void renderPieces();
	void render();
};
