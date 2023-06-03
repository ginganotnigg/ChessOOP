#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
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
	sf::Clock timer;

	// Mouse positions
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	// Board & Initial
	Board board;
	int repIdx;
	bool renderProm;
	int whiteTime;
	int blackTime;
	bool resign;
	bool timeout;
	int isWhite;
	bool stopEndgame;
	sf::RectangleShape promBox;
	sf::Texture promTxt[4];
	sf::Sprite prom[4];

	// Sounds
	sf::SoundBuffer soundBf[7];
	sf::Sound sound[7];

	// Texts
	sf::Font font;
	sf::Font font1;
	GUIText menuText[4];
	GUIText ingameText[4];
	GUIText replayText[3];
	GUIText endgameText[5];
	GUIText tutorialText[2];

	// Variables
	int draw_idx;
	bool soundLoop;
	bool replayPaused;

	// Background
	sf::Texture bgrTxt;
	sf::Sprite bgr;
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
	bool getEndgame();

	// Updating functions
	void promoteHover();
	void menuEvents();
	void ingameEvents();
	void replayEvents();
	void endgameEvents();
	void tutoEvents();
	void pollEvents();
	void updateWhiteTime();
	void updateBlackTime();
	void updateText();
	void updateMousePos();
	void updateBoard();
	void updateEndgame();
	void update();

	// Rendering functions
	void renderBoard();
	void renderBgr();
	void renderMenu();
	void renderIngame();
	void renderReplay();
	void renderEndgame();
	void renderPromote();
	void renderTutorial();
	void render();
};