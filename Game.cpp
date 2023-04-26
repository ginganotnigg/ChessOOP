#include "Game.h"

void Game::initVariables() {

}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600, 800), "Chess", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initFont() {
    //this->ingameFont.loadFromFile("Font/DisposableDroidBB_bld.ttf");
}

void Game::initText() {
    for (int i = 0; i < 3; i++) {
        this->ingameText[i].setFont(this->ingameFont);
        this->ingameText[i].setCharacterSize(24);
        this->ingameText[i].setFillColor(sf::Color::White);
        this->ingameText[i].setString("NONE");
    }
    for (int i = 0; i < 2; i++) {
        this->endgameText[i].setFont(this->ingameFont);
        this->endgameText[i].setCharacterSize(40);
        this->endgameText[i].setFillColor(sf::Color::Red);
        this->endgameText[i].setString("NONE");
    }
}

void Game::initBgr() {
    //this->bgrTxt.loadFromFile("");
    //this->bgr.setTexture(this->bgrTxt);
    //this->bgr.setColor(sf::Color());
    //this->bgr.scale();
}

void Game::initBoard() {

}



Game::Game() {
    this->initBgr();
    this->initBoard();
    this->initVariables();
    this->initWindow();
    this->initFont();
    this->initText();
}

Game::~Game() {
    delete this->window;
}

bool Game::running() {
    return this->window->isOpen();
}

bool Game::getFinish() {
    
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {

            // Window events
        case this->ev.Closed: {
            this->window->close();
            break;
        }

        case this->ev.MouseButtonPressed: {
            if (this->ev.key.code == sf::Mouse::Left) {

            }
            break;
        }

        }
    }
}

void Game::updateText() {

}

void Game::updateMousePos() {
    this->mousePos = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
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
    this->pollEvents();
    if (!this->getFinish()) {
        this->clickPieces();
        this->movePieces();
        this->capturePieces();
        this->checkmatePieces();
        this->updateText();
        this->updateMousePos();
    }
}

void Game::renderBgr() {
    this->window->draw(this->bgr);
}

void Game::renderBoard() {
    this->window->draw(this->board);
}

void Game::renderText() {
    for (int i = 0; i < 3; i++) {
        this->window->draw(this->ingameText[i]);
    }
}

void Game::renderEndgame() {
    for (int i = 0; i < 2; i++) {
        this->window->draw(this->endgameText[i]);
    }
}

void Game::renderPieces() {

}

void Game::render() {
    this->window->clear();
    this->renderBgr();
    if (!this->getFinish()) {
        this->renderBoard();
        this->renderText();
        this->renderPieces();
    }
    else {
        this->renderEndgame();
    }
    this->window->display();
}