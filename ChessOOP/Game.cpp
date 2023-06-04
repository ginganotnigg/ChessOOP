#pragma warning (disable: 26812)
#include "Game.h"

void Game::initVariables() {
    draw_idx = 1;
    soundLoop = true;
    replayPaused = false;
    renderProm = false;
    whiteTime = 600;
    blackTime = 601;
    isWhite = true;
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
    for (int i = 0; i < 7; i++) {
        sound[i].setBuffer(soundBf[i]);
    }
    sound[0].setLoop(soundLoop);
}

void Game::initFont() {
    font.loadFromFile("Font/DisposableDroidBB_bld.ttf");
    font1.loadFromFile("Font/FiraCode-Bold.ttf");
}

void Game::initText() {
    menuText[0].initText(font, 80, "NOOBCHESS", sf::Vector2f(390, 80), 1, sf::Color(255, 215, 158));
    menuText[0].text.setOutlineColor(sf::Color(209, 139, 71));
    menuText[0].text.setOutlineThickness(2.5);
    menuText[1].initText(font1, 35, "PVP", sf::Vector2f(360, 330), 2);
    menuText[2].initText(font1, 35, "HOW TO PLAY", sf::Vector2f(360, 400), 2);
    menuText[3].initText(font1, 35, "EXIT", sf::Vector2f(360, 540), 2);
    ingameText[0].initText(font, 40, "Undo", sf::Vector2f(835, 220), 2);
    ingameText[1].initText(font, 40, "Resign", sf::Vector2f(820, 340), 2);
    ingameText[2].initText(font, 40, "10:00", sf::Vector2f(322, -10), 1, sf::Color(150, 150, 150));
    ingameText[3].initText(font, 40, "10:00", sf::Vector2f(322, 670), 1, sf::Color(150, 150, 150));
    replayText[0].initText(font, 35, "<<", sf::Vector2f(815, 270), 2);
    replayText[1].initText(font, 35, ">>", sf::Vector2f(875, 270), 2);
    replayText[2].initText(font, 40, "Return", sf::Vector2f(805, 330), 2);
    endgameText[0].initText(font, 35, "Rematch", sf::Vector2f(822, 420), 2, sf::Color(209, 139, 71));
    endgameText[1].initText(font, 35, "Replay", sf::Vector2f(835, 480), 2, sf::Color(209, 139, 71));
    endgameText[2].initText(font, 35, "Return", sf::Vector2f(832, 540), 2, sf::Color(209, 139, 71));
    endgameText[3].initText(font, 45, "White win", sf::Vector2f(795, 240), 1, sf::Color(70, 90, 70));
    endgameText[4].initText(font, 30, "By resignation!", sf::Vector2f(785, 300), 1, sf::Color(70, 90, 70));

    string tuto = "The rules are the same as regular chess, except for those changes:\n\n\t- Each player has 10 minutes with no increments.\n\t- Since both players are noobs, they would be able to undo a move they dislike.\n However, the cost for one undo is 1/3 of total time (200 secs).\n\t- Player whose time reaches zero first loses.";
    tutorialText[0].initText(font1, 20, tuto, sf::Vector2f(50, 300), 1, sf::Color(255, 215, 158));
    tutorialText[1].initText(font1, 30, "Return", sf::Vector2f(470, 600), 2);
}

void Game::initBgr() {
    bgrTxt.loadFromFile("Image/Background.jpg");
    bgr.setTexture(bgrTxt);
    bgr.setColor(sf::Color(255, 255, 255, 120));
    bgr.scale(2.3f, 2.3f);
    whiteRect.setSize(sf::Vector2f(320, 400));
    whiteRect.setPosition(720, 200);
    whiteRect.setFillColor(sf::Color(255, 215, 158));
    whiteRect.setOutlineColor(sf::Color(191, 69, 63));
    whiteRect.setOutlineThickness(4);
}

void Game::initBoard() {
    board.initBoard();
    repIdx = 0;
    resign = false;
    timeout = false;
    whiteTime = 600;
    blackTime = 600;
    stopEndgame = false;
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
        prom[i].setColor(sf::Color(40, 80, 100, 150));
    }
}


Game::Game() {
    initBgr();
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

bool Game::getEndgame() {
    if ((resign || timeout || (board.allStates.size() > 2 && board.checkGameover() != '*')) && !stopEndgame) {
        draw_idx = 4;
        return true;
    }
    return false;
}

void Game::promoteHover() {
    for (int i = 0; i < 4; i++) {
        if (prom[i].getGlobalBounds().contains(mousePosView)) {
            prom[i].setColor(sf::Color(140, 180, 200, 230));
        }
        else {
            prom[i].setColor(sf::Color(40, 80, 100, 150));
        }
    }
}

void Game::menuEvents() {
    if (menuText[1].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        soundLoop = false;
        sound[0].stop();
        initBoard();
        draw_idx = 2;
    }
    if (menuText[2].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        soundLoop = false;
        sound[0].stop();
        draw_idx = 5;
    }
    if (menuText[3].text.getGlobalBounds().contains(mousePosView)) {
        window->close();
    }
}

void Game::ingameEvents() {
    if (ingameText[0].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        if (board.allStates.size() > 2) {
            if (isWhite && whiteTime > 200) {
                //whiteTime -= 280;
                whiteTime -= 200;
                board.undoMove();
                board.undoMove();
            }
            if (!isWhite && blackTime > 200) {
                blackTime -= 200;
                board.undoMove();
                board.undoMove();
            }
        }
    }
    if (ingameText[1].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        resign = true;
        draw_idx = 4;
    }
    if (prom[0].getGlobalBounds().contains(mousePosView)) {
        board.namePromote = 'q';
        sound[1].play();
        renderProm = false;
        board.isPromote = false;
    }
    if (prom[1].getGlobalBounds().contains(mousePosView)) {
        board.namePromote = 'r';
        sound[1].play();
        renderProm = false;
        board.isPromote = false;
    }
    if (prom[2].getGlobalBounds().contains(mousePosView)) {
        board.namePromote = 'n';
        sound[1].play();
        renderProm = false;
        board.isPromote = false;
    }
    if (prom[3].getGlobalBounds().contains(mousePosView)) {
        board.namePromote = 'b';
        sound[1].play();
        renderProm = false;
    }
}

void Game::replayEvents() {
    if (replayText[0].text.getGlobalBounds().contains(mousePosView) && repIdx > 0) {
        repIdx--;
        sound[1].play();
        board.loadState(repIdx);
    }
    if (replayText[1].text.getGlobalBounds().contains(mousePosView) && repIdx < board.allStates.size() - 1) {
        repIdx++;
        sound[1].play();
        board.loadState(repIdx);
    }
    if (replayText[2].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        draw_idx = 1;
        soundLoop = true;
    }
}

void Game::endgameEvents() {
    if (endgameText[0].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        stopEndgame = true;
        draw_idx = 2;
        initBoard();
    }
    if (endgameText[1].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        stopEndgame = true;
        draw_idx = 3;
        board.loadState(0);
    }
    if (endgameText[2].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        stopEndgame = true;
        draw_idx = 1;
    }
}

void Game::tutoEvents() {
    if (tutorialText[1].text.getGlobalBounds().contains(mousePosView)) {
        sound[1].play();
        soundLoop = true;
        draw_idx = 1;
    }
}

void Game::pollEvents() {
    while (window->pollEvent(ev)) {
        if (sound[0].getStatus() == sf::SoundSource::Status::Stopped && soundLoop) sound[0].play();
        // Window events
        switch (ev.type) {

        case this->ev.MouseMoved: {
            promoteHover();
            break;
        }

        case this->ev.Closed: {
            window->close();
            break;
        }

        case this->ev.MouseButtonReleased: {
            if (ev.key.code == sf::Mouse::Left) {
                // Menu button
                if (draw_idx == 1) {
                    menuEvents();
                }
                // Ingame button
                if (draw_idx == 2) {
                    ingameEvents();
                }
                // Replay button
                if (draw_idx == 3) {
                    replayEvents();
                }
                // Endgame button
                if (draw_idx == 4) {
                    endgameEvents();
                }
                if (draw_idx == 5) {
                    tutoEvents();
                }
            }
            break;
        }

        }
    }
}

void Game::updateWhiteTime() {
    std::stringstream sst;
    ingameText[3].text.setFillColor(sf::Color(255, 255, 255));
    ingameText[2].text.setFillColor(sf::Color(150, 150, 150));
    int duration = (int)timer.getElapsedTime().asSeconds();
    if (duration > 0 && whiteTime > 0) {
        whiteTime--;
        timer.restart();
    }
    sst << ((whiteTime / 60 < 10) ? "0" + to_string(whiteTime / 60) : to_string(whiteTime / 60)) << ":"
        << ((whiteTime % 60 < 10) ? "0" + to_string(whiteTime % 60) : to_string(whiteTime % 60));
    ingameText[3].text.setString(sst.str());
}

void Game::updateBlackTime() {
    std::stringstream sst;
    ingameText[2].text.setFillColor(sf::Color(255, 255, 255));
    ingameText[3].text.setFillColor(sf::Color(150, 150, 150));
    int duration = (int)timer.getElapsedTime().asSeconds();
    if (duration > 0 && blackTime > 0) {
        blackTime--;
        timer.restart();
    }
    sst << ((blackTime / 60 < 10) ? "0" + to_string(blackTime / 60) : to_string(blackTime / 60)) << ":"
        << ((blackTime % 60 < 10) ? "0" + to_string(blackTime % 60) : to_string(blackTime % 60));
    ingameText[2].text.setString(sst.str());
}

void Game::updateText() {
    for (int i = 0; i < 4; i++) {
        menuText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 4; i++) {
        ingameText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 3; i++) {
        replayText[i].update(ev, mousePosView);
    }
    for (int i = 0; i < 5; i++) {
        endgameText[i].update(ev, mousePosView);
    }
    tutorialText[1].update(ev, mousePosView);
}

void Game::updateMousePos() {
    mousePos = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePos);
}

void Game::updateBoard() {
    board.update(ev, mousePosView, sound);
    isWhite = board.whiteTurn();
    if (board.isPromote) {
        renderProm = true;
    }
    else {
        renderProm = false;
    }
    if (isWhite) {
        updateWhiteTime();
    }
    else {
        updateBlackTime();
    }
    if (whiteTime <= 0 || blackTime <= 0) {
        timeout = true;
    }
}

void Game::updateEndgame() {
    if (resign) {
        string alert = (isWhite) ? "Black win" : "White win";
        endgameText[3].text.setString(alert);
        endgameText[3].text.setPosition(sf::Vector2f(794 + isWhite, 240));
        endgameText[4].text.setString("By resignation!");
        endgameText[4].text.setPosition(sf::Vector2f(785, 300));
        return;
    }

    if (timeout) {
        string alert = (whiteTime <= 0) ? "Black win" : "White win";
        endgameText[3].text.setString(alert);
        endgameText[3].text.setPosition(sf::Vector2f(794 + isWhite, 240));
        endgameText[4].text.setString("By timeout!");
        endgameText[4].text.setPosition(sf::Vector2f(812, 300));
        return;
    }

    switch (board.checkGameover()) {

    case 'i': {
        endgameText[3].text.setString("Draw");
        endgameText[3].text.setPosition(sf::Vector2f(835, 240));
        endgameText[4].text.setString("By insufficient pieces!");
        endgameText[4].text.setPosition(sf::Vector2f(735, 300));
        break;
    }

    case 'f': {
        endgameText[3].text.setString("Draw");
        endgameText[3].text.setPosition(sf::Vector2f(835, 240));
        endgameText[4].text.setString("By 50-move rule!");
        endgameText[4].text.setPosition(sf::Vector2f(775, 300));
        break;
    }

    case 's': {
        endgameText[3].text.setString("Draw");
        endgameText[3].text.setPosition(sf::Vector2f(835, 240));
        endgameText[4].text.setString("By stalemate!");
        endgameText[4].text.setPosition(sf::Vector2f(795, 300));
        break;
    }

    case 'c': {
        string alert = (isWhite) ? "Black win" : "White win";
        endgameText[3].text.setString(alert);
        endgameText[3].text.setPosition(sf::Vector2f(794 + isWhite, 240));
        endgameText[4].text.setString("By checkmate!");
        endgameText[4].text.setPosition(sf::Vector2f(793, 300));
        break;
    }

    case '*':
        break;

    }
}

void Game::update() {
    updateMousePos();
    pollEvents();
    updateText();
    updateBoard();
    if (getEndgame()) {
        updateEndgame();
    }
}

void Game::renderBgr() {
    window->draw(bgr);
}

void Game::renderBoard() {
    if (draw_idx != 1) {
        board.render(window);
    }
}

void Game::renderMenu() {
    for (int i = 0; i < 4; i++) {
        menuText[i].render(window);
    }
}

void Game::renderIngame() {
    for (int i = 0; i < 4; i++) {
        ingameText[i].render(window);
    }
}

void Game::renderReplay() {
    for (int i = 0; i < 3; i++) {
        replayText[i].render(window);
    }
}

void Game::renderEndgame() {
    window->draw(whiteRect);
    for (int i = 0; i < 5; i++) {
        endgameText[i].render(window);
    }
}

void Game::renderPromote() {
    if (renderProm) {
        window->draw(promBox);
        for (int i = 0; i < 4; i++) {
            window->draw(prom[i]);
        }
    }
}

void Game::renderTutorial(){
    for (int i = 0; i < 2; i++) {
        tutorialText[i].render(window);
    }
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
        renderIngame();
        renderPromote();
        break;
    }

    case 3: {
        renderBoard();
        renderReplay();
        break;
    }

    case 4: {
        renderBoard();
        renderEndgame();
        break;
    }

    case 5: {
        renderTutorial();
        break;
    }

    }
    window->display();
}
