#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "headers/food.h"
#include "headers/gameobject.h"
#include "headers/map.h"
#include "headers/node.h"
#include "headers/sprite.h"

int main()
{
    // creates a window object using the Window constructor
    // parameters: videomode and title of the window
    // VideoMode is simply a type that defines the dimensions of the window (and bits per pixel)
    sf::RenderWindow window(sf::VideoMode(400, 300), "Pacman");

    window.create(sf::VideoMode::getFullscreenModes()[0], "SFML window", sf::Style::Fullscreen);

    // vertical sync is not supported by my device
    //window.setVerticalSyncEnabled (true);

    // another way to create a shape
    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);

    // .isOpen() method is from window class; we run a loop as long as the window is open
    while (window.isOpen())
    {
        // create an event object
        sf::Event event;

        // pollEvent method checks if the event queue is not empty
        while (window.pollEvent(event))
        {
            // x button is pressed
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // esc key is pressed
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }

            // else
            // {
            //     // send keyboard event to packman
            // }
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
    // window.display();

    window.close();
    return 0;
}
