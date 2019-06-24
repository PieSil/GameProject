#include <iostream>
#include <memory.h>
#include <SFML/Graphics.hpp>
#include "defaultValues.h"
#include "GameEntity.h"
#include "Knight.h"
#include "Wizard.h"

int main(){

    char selection;

    std::cout << "\nPress 'k' to select Knight, press 'w' to select Wizard" << std::endl;

    std::cin >> selection;

    sf::RenderWindow window(sf::VideoMode(640,480),
                            "GameProject");

    //GameEntity Test
    /*
    GameEntity block(window.getSize().x/2, window.getSize().y/2);
    block.setOrigin(block.getTexture().getSize().x/2., block.getTexture().getSize().y/2.);
    block.setPosition(window.getSize().x/2,window.getSize().y/2);
     //*/

    //Knight test

    std::unique_ptr<GameHero> hero = nullptr;

    switch(selection) {
        case 'k' :
            hero.reset(new Knight(window.getSize().x/2,window.getSize().y/2));
        case 'w':
            hero.reset(new Wizard(window.getSize().x/2,window.getSize().y/2));
            break;

        default:
            return 1;
    }

    
    //Knight knight(window.getSize().x/2,window.getSize().y/2);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                // Close window button clicked.
                window.close();
            } }
        window.clear(sf::Color::Black);
        // Draw here.

        //window.draw(knight.getSprite());
        window.draw(hero->getSprite());

        /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            heroSprite.move(HERO_SPEED,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {
            heroSprite.move(-HERO_SPEED,0);
        }*/

        //knight.updateMovement();

        if (Wizard* w = dynamic_cast<Wizard*>(hero.get())){
            w->updateInput();
        }
        if (Knight* k = dynamic_cast<Knight*>(hero.get())) {
            k->updateInput();
        }


        //hero->updateMovement();


        //dynamic_cast<Knight*>(hero)->updateMovement();


        window.display();
    }
}