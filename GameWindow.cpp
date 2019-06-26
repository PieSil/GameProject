//
// Created by Pietro on 2019-06-26.
//

#include "GameWindow.h"

GameWindow::GameWindow(const std::string &title, const sf::Vector2u &size) {
    setup(title, size);
}

GameWindow::~GameWindow() {
    destroy();
}

void GameWindow::setup(const std::string &title, const sf::Vector2u &size) {
    windowTitle = title;
    windowSize = size;
    fullScreen = false;
    closed = false;
    create();
}

void GameWindow::create() {

    //style type is sf::Uint32, a particular kind of integer type,
    //it is used to identify and select the window style
    //in this case the style selected is either Fullscreen or Default, based on the value of fullscreen
    auto style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;

    //create window:
    window.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle, style);
}

void GameWindow::destroy() {
    //closes window
    //update() method keeps polling events, their effects won't be displayed until window is recreated
    window.close();
}

void GameWindow::update() {
    sf::Event event;

    //polls event
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            //close window button click
            closed = true; //doesn't close window, simply updates the closed attibute
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) { //if F5 is pressed toggle fullscreen
            toggleFullscreen();
        }
    }
}

void GameWindow::toggleFullscreen() {
    fullScreen = !fullScreen;

    //destroys and recreates window to update style
    destroy();
    create();
}
