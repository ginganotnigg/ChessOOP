#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

enum GUI {
	label = 1,
	button = 2,
};

class GUIText {
public:
	sf::Text text;
	int type;

	GUIText();
	~GUIText();
	void initText(sf::Font& font, const int& size, const string& name, const sf::Vector2f& pos, const int& num);
	void update(sf::Event& e, sf::Vector2f& mouse);
	void render(sf::RenderWindow*& window);
};
