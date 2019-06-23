#include <iostream>
#include <SFML/Graphics.hpp>
#include "defaultValues.h"
#include "GameEntity.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(640,480),
                            "GameProject");
/*
    sf::RectangleShape rectangle(sf::Vector2f(128.0f,128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(320,240);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y /2);
*/

/*
    sf::Texture hero;
    if(!hero.loadFromFile("../GameAssets/Sprites/Player/Knight/Defence0/Player_Idle_Sword_Defence0_0.png")) {
        std::cout << "Failed to load image \"Player_Idle_Sword_Defence0_0.png\". Reason : Unable to open file" << std::endl;
    }
    sf::Sprite heroSprite(hero);
    heroSprite.setOrigin(hero.getSize().x/2., HERO_Y_ORIGIN);
    heroSprite.setPosition(window.getSize().x/2., window.getSize().y/2.);
*/

    //GameEntity Test
    GameEntity block;
    block.setOrigin(block.getTexture().getSize().x/2., block.getTexture().getSize().y/2.);
    block.setPosition(window.getSize().x/2,window.getSize().y/2);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                // Close window button clicked.
                window.close();
            } }
        window.clear(sf::Color::Black);
        // Draw here.


        //window.draw(heroSprite);
        window.draw(block.getSprite());
        
        /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            heroSprite.move(HERO_SPEED,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {
            heroSprite.move(-HERO_SPEED,0);
        }*/

        window.display();
    }
}