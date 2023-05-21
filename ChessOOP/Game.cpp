#pragma warning (disable: 26812)
#include "Game.h"

void Game::initVariables() {
    draw_idx = 1;
    soundLoop = true;
    replayPaused = false;
    renderProm = true;
}

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Chess", sf::Style::Close | sf::Style::Resize);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(false);
    settings.antialiasingLevel = 8;
}

void Game::initSound() {
    soundBf[0].loadFromFile("Sound/music.wav");
    soundBf[1].loadFromFile("Sound/click.wav");
    soundBf[2].loadFromFile("Sound/move.wav");
    soundBf[3].loadFromFile("Sound/capture.wav");
    soundBf[4].loadFromFile("Sound/check.wav");
    soundBf[5].loadFromFile("Sound/notify.wav");
    soundBf[6].loadFromFile("Sound/gameover.wav");
    for (int i = 0; i < 6; i++) {
        sound[i].setBuffer(soundBf[i]);
    }
    sound[0].setLoop(soundLoop);
}

void Game::initFont() {
    font.loadFromFile("Font/DisposableDroidBB_bld.ttf");
}

void Game::initText() {
    menuText[0].initText(font, 60, "NOOBCHESS", sf::Vector2f(430, 60), 1, sf::Color(255, 215, 158));
    menuText[0].text.setOutlineColor(sf::Color(209, 139, 71));
    menuText[0].text.setOutlineThickness(2.5);
    menuText[1].initText(font, 35, "Play Human", sf::Vector2f(360, 330), 2);
    menuText[2].initText(font, 35, "Play Easy Bot", sf::Vector2f(360, 400), 2);
    menuText[3].initText(font, 35, "Play Hard Bot", sf::Vector2f(360, 470), 2);
    menuText[4].initText(font, 35, "Exit", sf::Vector2f(360, 540), 2);
    ingameText[0].initText(font, 35, "Undo", sf::Vector2f(780, 220), 2);
    ingameText[1].initText(font, 35, "Redo", sf::Vector2f(900, 220), 2);
    ingameText[2].initText(font, 35, "Flip Board", sf::Vector2f(800, 300), 2);
    ingameText[3].initText(font, 40, "Resign", sf::Vector2f(820, 420), 2);
    replayText[0].initText(font, 35, "<<", sf::Vector2f(780, 270), 2);
    replayText[1].initText(font, 35, "[]", sf::Vector2f(845, 270), 2);
    replayText[2].initText(font, 35, ">>", sf::Vector2f(900, 270), 2);
    replayText[3].initText(font, 40, "Return", sf::Vector2f(800, 390), 2);
    endgameText[0].initText(font, 35, "Rematch", sf::Vector2f(390, 420), 2, sf::Color(209, 139, 71));
    endgameText[1].initText(font, 35, "Replay", sf::Vector2f(600, 420), 2, sf::Color(209, 139, 71));
    endgameText[2].initText(font, 35, "Return", sf::Vector2f(500, 480), 2, sf::Color(209, 139, 71));
}

void Game::initBgr() {
    bgrTxt.loadFromFile("Image/Background.jpg");
    bgr.setTexture(bgrTxt);
    bgr.setColor(sf::Color(255, 255, 255, 120));
    bgr.scale(2.3f, 2.3f);
    whiteRect.setSize(sf::Vector2f(500, 400));
    whiteRect.setPosition(290, 160);
    whiteRect.setFillColor(sf::Color(255, 215, 158));
    whiteRect.setOutlineColor(sf::Color(191, 69, 63));
    whiteRect.setOutlineThickness(4);
}

void Game::initBoard() {
    board.initBoard();
}

void Game::initPromote() {
    promBox.setSize(sf::Vector2f(280, 70));
    promBox.setPosition(730, 100);
    promBox.setFillColor(sf::Color(255, 215, 158));
    promBox.setOutlineColor(sf::Color(191, 69, 63));
    promBox.setOutlineThickness(4);
    promTxt[0].loadFromFile("Image/wQ.png");
    prom[0].setTexture(promTxt[0]);
    promTxt[1].loadFromFile("Image/wR.png");
    prom[1].setTexture(promTxt[1]);
    promTxt[2].loadFromFile("Image/wN.png");
    prom[2].setTexture(promTxt[2]);
    promTxt[3].loadFromFile("Image/wB.png");
    prom[3].setTexture(promTxt[3]);
    for (int i = 0; i < 4; i++) {
        prom[i].setPosition(730 + 70.0 * i, 100);
    }
}

Game::Game() {
    initBgr();
    initBoard();
    initVariables();
    initWindow();
    initSound();
    initFont();
    initText();
    initPromote();
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
        if (sound[0].getStatus() == sf::SoundSource::Status::Stopped && soundLoop) sound[0].play();
        // Window events
        switch (ev.type) {

        case this->ev.Closed: {
            window->close();
            break;
        }

        case this->ev.MouseButtonReleased: {
            if (ev.key.code == sf::Mouse::Left) {
                // Menu button
                if (menuText[1].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    soundLoop = false;
                    sound[0].stop();
                    draw_idx = 2;
                }
                if (menuText[2].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    soundLoop = false;
                    sound[0].stop();
                    draw_idx = 2;
                }
                if (menuText[3].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    soundLoop = false;
                    sound[0].stop();
                    draw_idx = 2;
                }
                if (menuText[4].text.getGlobalBounds().contains(mousePosView)) {
                    window->close();
                }
                // Ingame button
                if (ingameText[3].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    draw_idx = 4;
                }
                if (prom[0].getGlobalBounds().contains(mousePosView)) {
                    renderProm = false;
                }
                if (prom[1].getGlobalBounds().contains(mousePosView)) {
                    renderProm = false;
                }
                if (prom[2].getGlobalBounds().contains(mousePosView)) {
                    renderProm = false;
                }
                if (prom[3].getGlobalBounds().contains(mousePosView)) {
                    renderProm = false;
                }
                // Replay button
                if (replayText[1].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    replayPaused = !replayPaused;
                    if (replayPaused) {
                        replayText[1].text.setString("#");
                    }
                    else {
                        replayText[1].text.setString("[]");
                    }
                }
                if (replayText[3].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    draw_idx = 1;
                    soundLoop = true;
                }
                // Endgame button
                if (endgameText[0].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    draw_idx = 2;
                }
                if (endgameText[1].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    draw_idx = 3;
                }
                if (endgameText[2].text.getGlobalBounds().contains(mousePosView)) {
                    sound[1].play();
                    draw_idx = 1;
                    soundLoop = true;
                }
            }
            break;
        }

        }
    }
}

void Game::updateText() {
    for (int i = 0; i < 5; i++) {
        menuText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 5; i++) {
        ingameText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 4; i++) {
        replayText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 5; i++) {
        endgameText[i].update(ev, mousePosView);
    }
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
    board.render(window);
}

void Game::renderPromote() {
    if (!renderProm) {
        return;
    }
    window->draw(promBox);
    for (int i = 0; i < 4; i++) {
        window->draw(prom[i]);
    }
}

void Game::renderMenu() {
    for (int i = 0; i < 5; i++) {
        menuText[i].render(window);
    }
}

void Game::renderIngame() {
    for (int i = 0; i < 5; i++) {
        ingameText[i].render(window);
    }
}

void Game::renderReplay() {
    for (int i = 0; i < 4; i++) {
        replayText[i].render(window);
    }
}

void Game::renderEndgame() {
    window->draw(whiteRect);
    for (int i = 0; i < 5; i++) {
        endgameText[i].render(window);
    }
}

void Game::renderPieces() {

}

void Game::render() {
    window->clear();
    renderBgr();
    switch (draw_idx) {
    case 1: {
        renderMenu();
        break;
    }

    case 2: {
        renderBoard();
        renderPieces();
        renderIngame();
        renderPromote();
        break;
    }

    case 3: {
        renderBoard();
        renderPieces();
        renderReplay();
        break;
    }

    case 4: {
        renderBoard();
        renderPieces();
        renderEndgame();
        break;
    }

    }
    window->display();
}
