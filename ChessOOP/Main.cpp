#include "Game.h"
#include <SFML/System.hpp>

void timeout() {
	sf::sleep(sf::milliseconds(50));
}

int main() {

	Game game;
	sf::Thread thread(&timeout);
	while (game.running()) {
		game.update();
		game.render();
		thread.launch();
	}

	return 0;
}
