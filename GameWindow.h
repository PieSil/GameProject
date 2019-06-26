//
// Created by Pietro on 2019-06-26.
//

#ifndef GAMEPROJECT_GAMEWINDOW_H
#define GAMEPROJECT_GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameWindow {
public:
    GameWindow(const std::string& title, const sf::Vector2u& size);

    //default constructor
    GameWindow();

    ~GameWindow();

    void beginDraw(); //clear the window
    void EndDraw(); //display the changes

    void update();

    void toggleFullscreen();

    void draw(sf::Drawable& drawable);

    bool isDone() const;

    bool isFullScreen() const;

    const sf::Vector2u &getWindowSize() const {
        return windowSize;
    }

    void setWindowSize(const sf::Vector2u &windowSize) {
        GameWindow::windowSize = windowSize;
    }


private:
    void setup(const std::string& title, const sf::Vector2u& size);

    void destroy();
    void create();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool done;
    bool fullScreen;

};


#endif //GAMEPROJECT_GAMEWINDOW_H
