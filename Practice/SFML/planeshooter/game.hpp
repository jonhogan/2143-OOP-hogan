#include <SFML/Graphics.hpp>

class GAME
{
    protected:
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;
    
    public:

        GAME()
        {
            
        }
        void Run();
        void ProcessEvents();
        void Update();
        void Render();

};