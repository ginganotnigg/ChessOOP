#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include "GUIText.h"

using namespace std;

class Game {
private:
	// Window
	int width = 1080;
	int height = 720;
	sf::RenderWindow* window;
	sf::Event ev;

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
	GUIText endgameText[5];

	// Variables
	int draw_idx;
	bool soundLoop;

	// Background
	sf::Texture boardTxt;
	sf::Sprite board;
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

public:
	// Cons & Dest
	Game();
	virtual ~Game();

	// Accessors
	bool running();
	bool getFinish();

	// Functions
	void pollEvents();
	void updateText();
	void updateMousePos();

	void clickPieces();
	void capturePieces();
	void movePieces();
	void checkmatePieces();

	void update();

	void renderBoard();
	void renderBgr();
	void renderMenu();
	void renderIngame();
	void renderEndgame();
	void renderPieces();
	void render();
};
