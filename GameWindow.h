//
// Created by Pietro on 2019-06-26.
//

#ifndef GAMEPROJECT_GAMEWINDOW_H
#define GAMEPROJECT_GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameWindow {
public:
    explicit GameWindow(const std::string& title = "Window", const sf::Vector2u& size = sf::Vector2u(1140,640));

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

    void setView(const sf::View& view) {
        window.setView(view);
    }

    void update();

    void toggleFullscreen();

    void draw(const sf::Drawable& drawable) {
        window.draw(drawable);
    }

    bool isClosed() const {
        return closed;
    }

    void setClosed(bool closed) {
        GameWindow::closed = closed;
    }

    bool isFullScreen() const {
        return fullScreen;
    }

    const sf::Vector2u &getWindowSize() const {
        return windowSize;
    }

    const sf::RenderWindow &getRenderWindow() const {
        return window;
    }

    void clear(const sf::Color &color) {
        window.clear(color);
    }

    const sf::Sprite &getBackground() const {
        return background;
    }

    bool setBackground(const std::string &path, const float &heroPosY) {
        bool result = false;
        if (texture.loadFromFile(path)) {
            background.setTexture(texture);
            result = true;
        }

        background.setOrigin(background.getOrigin().x, background.getTextureRect().height/2.);
        background.setPosition(background.getPosition().x, heroPosY);

        return result;
    }


private:
    //manage the window internally, setup(), create(), destroy() are not part of the interface
    void setup(const std::string& title, const sf::Vector2u& size);

    void destroy();

    void create();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
    std::string windowTitle;
    sf::Texture texture;
    sf::Sprite background;
    bool closed;
    bool fullScreen;

};


#endif //GAMEPROJECT_GAMEWINDOW_H
