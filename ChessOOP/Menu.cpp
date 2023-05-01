#include "Menu.h"

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::initText() {
	title.initText(font, 50, "NERDCHESS", sf::Vector2f(420, 60), 1);
	button[0].initText(font, 35, "Play Human", sf::Vector2f(360, 330), 2);
	button[1].initText(font, 35, "Play Easy Bot", sf::Vector2f(360, 400), 2);
	button[2].initText(font, 35, "Play Hard Bot", sf::Vector2f(360, 470), 2);
	button[3].initText(font, 35, "Exit", sf::Vector2f(360, 540), 2);
}

void Menu::update(sf::Event& e, sf::Vector2f& mouse) {
	for (int i = 0; i < MAX_ITEMS_NUMBER; i++) {
		button[i].update(e, mouse);
	}
}

void Menu::render(sf::RenderWindow*& window) {
	title.render(window);
	for (int i = 0; i < MAX_ITEMS_NUMBER; i++) {
		button[i].render(window);
	}
}