#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "GUIText.h"

using namespace std;

#define MAX_ITEMS_NUMBER 4

class Menu {
public:
	sf::Font font;
	GUIText title;
	GUIText button[MAX_ITEMS_NUMBER];

	Menu();
	~Menu();
	void initText();
	void update(sf::Event& e, sf::Vector2f& mouse);
	void render(sf::RenderWindow*& window);
};