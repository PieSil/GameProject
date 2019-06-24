#include <iostream>
#include <SFML/Graphics.hpp>
#include "defaultValues.h"
#include "GameEntity.h"
#include "Knight.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(640,480),
                            "GameProject");


    //GameEntity Test
    /*
    GameEntity block(window.getSize().x/2, window.getSize().y/2);
    block.setOrigin(block.getTexture().getSize().x/2., block.getTexture().getSize().y/2.);
    block.setPosition(window.getSize().x/2,window.getSize().y/2);
     //*/

    //Knight test
    Knight knight(window.getSize().x/2,window.getSize().y/2);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                // Close window button clicked.
                window.close();
            } }
        window.clear(sf::Color::Black);
        // Draw here.


        //window.draw(gameEntity);
        //window.draw(block.getSprite());

        //window.draw(knight);
        window.draw(knight.getSprite());
        
        /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            heroSprite.move(HERO_SPEED,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {
            heroSprite.move(-HERO_SPEED,0);
        }*/
        knight.updateMovement();

        window.display();
    }
}