#include <SFML/Graphics.hpp>
#include "Game.hpp"

/***********************************************************************************************
 
 
                              __       __  ______  _______  
                             |  \  _  |  \|      \|       \ 
                             | $$ / \ | $$ \$$$$$$| $$$$$$$\
                             | $$/  $\| $$  | $$  | $$__/ $$
                             | $$  $$$\ $$  | $$  | $$    $$
                             | $$ $$\$$\$$  | $$  | $$$$$$$ 
                             | $$$$  \$$$$ _| $$_ | $$      
                             | $$$    \$$$|   $$ \| $$      
                              \$$      \$$ \$$$$$$ \$$      

***********************************************************************************************/


int main()
{
    int window_width = 600;
    int window_height = 600;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JHOGAN Game", sf::Style::Default);
    
    PLAYER B(window_width,window_height);
       

    while (window.isOpen())
     {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            switch(event.type)
            {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                
                case sf::Event::EventType::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        // move up...
                        B.move(1);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        // move left...
                        B.move(1);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        // move down...
                        B.move(-1);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        // move down...
                        B.move(-1);
                    }
            }
            
                
        }

       
        
        


        window.clear();
        window.draw(B);
        window.display();
    }

    return 0;
}