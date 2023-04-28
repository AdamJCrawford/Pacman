#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <sstream>

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
    sf::RenderWindow window(sf::VideoMode(500, 500), "Pacman");

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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                curr_key = 1;
            }

            // Pacman moves leftevent.key.code == sf::Keyboard::A)
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                curr_key = 2;
            }

            // Pacman moves down
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                curr_key = 3;
            }

            // Pacman moves right
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                curr_key = 4;
            }
        }

        window.clear();
        // j is the y value of the position
        // things can move more than once

        bool characters_added = 0;

        for (int j = 0; j < 25; j++)
        {
            // i is the x value of the position
            for (int i = 0; i < 25; i++)
            {
                for (auto obj: map.map[i][j].get_current_objs())
                {
                    if (obj)
                    {
                        if (obj->name == "Pacman")
                        {
                            (static_cast<Pacman *>(obj))->move(&map);
                            if (!characters_added)
                            {
                                characters.push_back(obj);
                            }
                        }
                        if (obj->name == "Ghost")
                        {
                            (static_cast<Ghost *>(obj))->move(&map);
                            if (!characters_added)
                            {
                                characters.push_back(obj);
                            }
                        }

                        window.draw(obj->draw());
                    }
                }
            }
        }
        characters_added = 1;
        for (auto character: characters)
        {
            if (character->name == "Ghost")
            {
                (static_cast<Ghost *>(character))->reset();
            }
            else
            {
                (static_cast<Pacman *>(character))->reset();
            }
        }
        // map.print_map();
        // std::cout << "\n";
        window.setTitle("Score: " + std::to_string(score));

        window.display();
    }
    // window.display();

    window.close();
    return 0;
}
