#include "Game.h"

void Game::initVariables() {

}

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Chess", sf::Style::Close | sf::Style::Resize);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(false);
}

void Game::initFont() {
    ingameFont.loadFromFile("Font/DisposableDroidBB_bld.ttf");
    menu.font = ingameFont;
}

void Game::initText() {
    menu.initText();
}

void Game::initBgr() {
    bgrTxt.loadFromFile("Image/Background.jpg");
    bgr.setTexture(bgrTxt);
    bgr.setColor(sf::Color(255, 255, 255, 120));
    bgr.scale(2.3, 2.3);
}

void Game::initBoard() {

}



Game::Game() {
    initBgr();
    initBoard();
    initVariables();
    initWindow();
    initFont();
    initText();
}

Game::~Game() {
    delete window;
}

bool Game::running() {
    return window->isOpen();
}

bool Game::getFinish() {
    return false;
}

void Game::pollEvents() {
    while (window->pollEvent(ev)) {
        menu.update(ev, mousePosView);

        // Window events
        switch (ev.type) {

        case this->ev.Closed: {
            window->close();
            break;
        }

        case this->ev.MouseButtonReleased: {
            if (ev.key.code == sf::Mouse::Left) {
                if (menu.button[0].text.getGlobalBounds().contains(mousePosView)) {
                    cout << "Button 1 is clicked\n";
                }
                if (menu.button[1].text.getGlobalBounds().contains(mousePosView)) {
                    cout << "Button 2 is clicked\n";
                }
                if (menu.button[2].text.getGlobalBounds().contains(mousePosView)) {
                    cout << "Button 3 is clicked\n";
                }
                if (menu.button[3].text.getGlobalBounds().contains(mousePosView)) {
                    window->close();
                }
            }
            break;
        }

        }
    }
}

void Game::updateText() {

}

void Game::updateMousePos() {
    mousePos = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePos);
}

void Game::clickPieces() {

}

void Game::movePieces() {

}

void Game::capturePieces() {

}

void Game::checkmatePieces() {

}

void Game::update() {
    updateMousePos();
    pollEvents();
    if (running()) {
        clickPieces();
        movePieces();
        capturePieces();
        checkmatePieces();
        updateText();
        updateMousePos();
    }
}

void Game::renderBgr() {
    window->draw(bgr);
}

void Game::renderBoard() {
    window->draw(board);
}

void Game::renderMenu() {
    menu.render(window);
}

void Game::renderText() {
    for (int i = 0; i < 3; i++) {
        window->draw(ingameText[i]);
    }
}

void Game::renderEndgame() {
    for (int i = 0; i < 2; i++) {
        window->draw(endgameText[i]);
    }
}

void Game::renderPieces() {

}

void Game::render() {
    window->clear();
    renderBgr();
    if (running()) {
        renderMenu();
        renderBoard();
        renderText();
        renderPieces();
    }
    else {
        renderEndgame();
    }
    window->display();
}