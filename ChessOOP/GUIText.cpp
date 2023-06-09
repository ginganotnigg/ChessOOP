#include "GUIText.h"

GUIText::GUIText() {
	type = 1;
	defColor = sf::Color::White;
}

GUIText::~GUIText() {
}

void GUIText::initText(sf::Font& font, const int& size, const string& name, const sf::Vector2f& pos, const int& num, sf::Color color) {
	text.setFont(font);
	defColor = color;
	text.setFillColor(defColor);
	text.setCharacterSize(size);
	text.setString(name);
	text.setPosition(pos);
	type = num;
}

void GUIText::update(sf::Event& e, sf::Vector2f& mouse) {
	if (type == GUI::label) {
		return;
	}
	switch (e.type) {

	case e.MouseMoved: {
		if (text.getGlobalBounds().contains(mouse)) {
			text.setFillColor(sf::Color(191, 69, 63));
		}
		else {
			text.setFillColor(defColor);
		}
		break;
	}

	case e.MouseButtonPressed: {
		if (e.key.code == sf::Mouse::Left && text.getGlobalBounds().contains(mouse)) {
			text.setFillColor(sf::Color::Red);
		}
		else {
			text.setFillColor(defColor);
		}
		break;
	}

	case e.MouseButtonReleased: {
		if (e.key.code == sf::Mouse::Left && text.getGlobalBounds().contains(mouse)) {
			text.setFillColor(sf::Color(191, 69, 63));
		}
		else {
			text.setFillColor(defColor);
		}
		break;
	}

	}
}

void GUIText::render(sf::RenderWindow*& window) {
	window->draw(text);
}