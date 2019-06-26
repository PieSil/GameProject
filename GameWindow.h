//
// Created by Pietro on 2019-06-26.
//

#ifndef GAMEPROJECT_GAMEWINDOW_H
#define GAMEPROJECT_GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameWindow {
public:
    explicit GameWindow(const std::string& title = "Window", const sf::Vector2u& size = sf::Vector2u(640,480));

    ~GameWindow();

    void beginDraw() {
        //clears window, background color is black
        window.clear(sf::Color::Black);
    }

    //clear the window
    void endDraw() {
        //displays window
        window.display();
    }
    //display the changes

    void update();

    void toggleFullscreen();

    void draw(const sf::Drawable& drawable) {
        window.draw(drawable);
    }

    bool isClosed() const {
        return closed;
    }

    bool isFullScreen() const {
        return fullScreen;
    }

    const sf::Vector2u &getWindowSize() const {
        return windowSize;
    }



private:
    //manage the window internally, setup(), create(), destroy() are not part of the interface
    void setup(const std::string& title, const sf::Vector2u& size);

    void destroy();

    void create();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    bool closed;
    bool fullScreen;

};


#endif //GAMEPROJECT_GAMEWINDOW_H
