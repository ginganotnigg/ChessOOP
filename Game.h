#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>


class Game {
private:
	// Window
	sf::RenderWindow* window;
	sf::Event ev;

	// Mouse positions
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	// Board & Pieces

	// Texts
	sf::Font ingameFont;
	sf::Text ingameText[3];
	sf::Text endgameText[2];

	// Variables

	// Background
	sf::Texture boardTxt;
	sf::Sprite board;
	sf::Texture bgrTxt;
	sf::Sprite bgr;

	// Private funcs
	void initVariables();
	void initWindow();
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
	bool endStage();
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
	void renderText();
	void renderEndgame();
	void renderPieces();
	void render();
};
