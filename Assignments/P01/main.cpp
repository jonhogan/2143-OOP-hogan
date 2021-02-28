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

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "JHOGAN Game");
    
    PLAYER B(window_width,window_height);

    

    while (window.isOpen())
     {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       
        
        B.update();


        window.clear();
        window.draw(B);
        window.display();
    }

    return 0;
}