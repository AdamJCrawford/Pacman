#include <iostream>
#include <string>
// #include <vector>
#include <SFML/Graphics.hpp>

#include "headers/globals.h"
#include "headers/cookie.h"
#include "headers/pacdot.h"
#include "headers/map.h"
#include "headers/pacman.h"
#include "headers/ghost.h"

int main()
{
    // creates a window object using the Window constructor
    // parameters: videomode and title of the window
    // VideoMode is simply a type that defines the dimensions of the window (and bits per pixel)
    sf::RenderWindow window(sf::VideoMode(500, 480), "Pacman");

    window.setFramerateLimit(5);

    // window.create(sf::VideoMode::getFullscreenModes()[0], "SFML window", sf::Style::Fullscreen);

    // vertical sync is not supported by my device
    //window.setVerticalSyncEnabled (true);

    Map map;

    map.create_map();
    // Pacdot pacdot(20, 20);

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
            // else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            // {
            //     window.close();
            // }

            // Pacman moves up
            else if ((event.type == sf::Event::KeyPressed) && ((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::W)))
            {
                curr_key = 1;
            }

            // Pacman moves left
            else if ((event.type == sf::Event::KeyPressed) && ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::A)))
            {
                curr_key = 2;
            }

            // Pacman moves down
            else if ((event.type == sf::Event::KeyPressed) && ((event.key.code == sf::Keyboard::Down) || (event.key.code == sf::Keyboard::S)))
            {
                curr_key = 3;
            }

            // Pacman moves right
            else if ((event.type == sf::Event::KeyPressed) && ((event.key.code == sf::Keyboard::Right) || (event.key.code == sf::Keyboard::D)))
            {
                curr_key = 4;
            }

            window.clear();
            // j is the y value of the position
            for (int j = 0; j < 25; j++)
            {
                // i is the x value of the position
                for (int i = 0; i < 24; i++)
                {
                    if (map.map[i][j].get_current_obj())
                    {
                        if (map.map[i][j].get_current_obj()->name == "Pacman")
                        {
                            (static_cast<Pacman *>(map.map[i][j].get_current_obj()))->move(&map);
                        }
                        if (map.map[i][j].get_current_obj()->name == "Ghost")
                        {
                            (static_cast<Ghost *>(map.map[i][j].get_current_obj()))->move();
                        }

                        window.draw(map.map[i][j].get_current_obj()->draw());
                    }
                }
            }

            // window.draw(cookie.draw());
            // window.draw(pacdot.draw());

            window.display();
        }
    }
    // window.display();

    window.close();
    return 0;
}
