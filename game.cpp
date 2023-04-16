#include <iostream>
// #include <vector>
#include <SFML/Graphics.hpp>

#include "headers/globals.h"
#include "headers/cookie.h"
#include "headers/pacdot.h"
#include "headers/map.h"

int main()
{
    // creates a window object using the Window constructor
    // parameters: videomode and title of the window
    // VideoMode is simply a type that defines the dimensions of the window (and bits per pixel)
    sf::RenderWindow window(sf::VideoMode(600, 600), "Pacman");

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

            window.clear();
            for(int i = 0; i < 25; i++)
            {
                for(int j = 0; j < 24; j++)
                {
                    std::cout << map.map[i][j].get_pos().x << ' ' << map.map[i][j].get_pos().y << "\n";
                    if(map.map[i][j].get_current_obj())
                    {
                        std::cout << map.map[i][j].get_current_obj()->name << "\n";
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
  