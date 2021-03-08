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
    int window_width = 820;
    int window_height = 600;
    DEBRIS debris[5];

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JHOGAN Game", sf::Style::Default);
    PLAYER B(window_width,window_height, 15);
    DEBRIS A(window_width,window_height);
    

    for (int i = 0; i < 5; i++)
    {
        debris[i] = A;
    }
       

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
                        B.moveUp(-5);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        // move left...
                        B.moveUp(-5);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        // move down...
                        B.moveDown(5);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        // move down...
                        B.moveDown(5);
                    }
                    break;
            }

            
            
                
        }

       
        A.move(-5);
        


        window.clear();
        window.draw(B);
        
        window.draw(A);
        window.display();
    }

    return 0;
}