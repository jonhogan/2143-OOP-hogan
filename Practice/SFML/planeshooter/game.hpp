#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

/***************************************************************************
****************************************************************************
**   ______   __    __   ______    ______   ________  ________  _______   **
**  /      \ /  |  /  | /      \  /      \ /        |/        |/       \  **
** /$$$$$$  |$$ |  $$ |/$$$$$$  |/$$$$$$  |$$$$$$$$/ $$$$$$$$/ $$$$$$$  | **
** $$ \__$$/ $$ |__$$ |$$ |  $$ |$$ |  $$ |   $$ |   $$ |__    $$ |__$$ | **
** $$      \ $$    $$ |$$ |  $$ |$$ |  $$ |   $$ |   $$    |   $$    $$<  **
**  $$$$$$  |$$$$$$$$ |$$ |  $$ |$$ |  $$ |   $$ |   $$$$$/    $$$$$$$  | **
** /  \__$$ |$$ |  $$ |$$ \__$$ |$$ \__$$ |   $$ |   $$ |_____ $$ |  $$ | **
** $$    $$/ $$ |  $$ |$$    $$/ $$    $$/    $$ |   $$       |$$ |  $$ | **
**  $$$$$$/  $$/   $$/  $$$$$$/   $$$$$$/     $$/    $$$$$$$$/ $$/   $$/  **
**                                                                        **
**                                                                        **
**                                                                        **
**               ______    ______   __       __  ________                 **
**              /      \  /      \ /  \     /  |/        |                **
**             /$$$$$$  |/$$$$$$  |$$  \   /$$ |$$$$$$$$/                 **
**             $$ | _$$/ $$ |__$$ |$$$  \ /$$$ |$$ |__                    **
**             $$ |/    |$$    $$ |$$$$  /$$$$ |$$    |                   **
**             $$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/                    **
**             $$ \__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____                 **
**             $$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |                **
**              $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/                 **
**                                                                        **
**                                                                        **
****************************************************************************                                                                       
***************************************************************************/

/**********************************************************************
***********************************************************************
*                                                                     *
* GAME                                                                *
*                                                                     *
* Description:                                                        *
*       GAME class, will handle game related inputs                   *
*                                                                     *
* Private Methods:                                                    *
*       None                                                          *
*                                                                     *
* Protected Methods:                                                  *
*       sf::RenderWindow m_window; Game window                        *
*       sf::CircleShape m_player;  Player object                      *
*                                                                     *
* Public Methods:                                                     *
*       GAME                 *                                        *
*       Run                  * See notes                              *
*       ProcessEvents        * below on                               *
*       Update               * usage                                  *
*       Render               *                                        *
*                            *                                        *
***********************************************************************
**********************************************************************/

const sf::Time FRAMETIME = sf::seconds(1.f/60.f);

class Game
{
    protected:
        const float PLAYERSPEED = 100.f;

        sf::RenderWindow m_window;
        sf::Sprite m_player;
        sf::Texture m_playerTexture;


        bool m_moveUp = false;
        bool m_moveDown = false;

    public:

        /******************************************************************
        *                                                                 *
        * Game                                                            *
        *                                                                 *
        * Description:                                                    *
        *       Holds the game window, m_player object and anyother       *
        *       objects in game.                                          *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *   Creates our game object                                       *
        *                                                                 *
        ******************************************************************/
        Game(): m_window(
            sf::VideoMode(1920,1080), "Game Window",
            sf::Style::Default), m_player(), m_playerTexture()
        {
            if(!m_playerTexture.loadFromFile("Spaceship3.png"))
            {
                std::cout << "Texture not found!";
            }
            m_player.setTexture(m_playerTexture);
            m_player.setPosition(160.f,500.f);
            //m_player.rotate(90.f);


        }

        /******************************************************************
        *                                                                 *
        * Run                                                             *
        *                                                                 *
        * Description:                                                    *
        *       Holds the window while loop.                              *
        *                                                                 *
        * Method Variables:                                               *
        *   sf::Clock t_clock                                             *
        * Use:                                                            *
        *   Runs the processes to run the game whilewindow.isOpen = true  *
        *                                                                 *
        ******************************************************************/

        void Run()
        {
            sf::Clock t_clock;

            /*

                Implementing fixed time steps.

                Helps to solve issues with lag. This will help prevent
                colliding objects from passing through eachother

            */

            sf::Time t_lastUpdate = sf::Time::Zero;

            while (m_window.isOpen())
            {
                ProcessEvents();
                t_lastUpdate += t_clock.restart();
                while (t_lastUpdate > FRAMETIME)
                {
                    t_lastUpdate -= FRAMETIME;
                    ProcessEvents();
                    Update(FRAMETIME);
                }
                Render();
            }

        }
 
        /******************************************************************
        *                                                                 *
        * ProcessEvents                                                   *
        *                                                                 *
        * Description:                                                    *
        *       Polls events in game, key presses, mouse clicks and       *
        *       other events                                              *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *   Runs the pollEvent while loop                                 *
        *                                                                 *
        ******************************************************************/
        void ProcessEvents()
        {
            sf::Event event;
         while (m_window.pollEvent(event)) 
            {
                switch(event.type)
                {
                    case sf::Event::KeyPressed:
                         handlePlayerInput(event.key.code, true);
                         break;
                    case sf::Event::KeyReleased:
                         handlePlayerInput(event.key.code, false);
                         break;
                    case sf::Event::Closed:
                        m_window.close();
                        break;
                }
                        
            }
        }
        

        /******************************************************************
        *                                                                 *
        * Update                                                          *
        *                                                                 *
        * Description:                                                    *
        *   Updates the status of the game. Includes player and game      *
        *   objects (Non-player controlled)                               *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *                                                                 *
        ******************************************************************/

        void Update(sf::Time dTime)
        {
            sf::Vector2f t_movement(0.f, 0.f);
            if (m_player.getPosition().y >= 0)
            {
                if(m_moveUp)
                {
                    t_movement.y -= PLAYERSPEED;
                }
                m_player.move(t_movement * dTime.asSeconds());
            }
            if (m_player.getPosition().y <= 1035)
            {
                if(m_moveDown)
                {
                    float t_downSpeed = PLAYERSPEED*2;
                    t_movement.y += t_downSpeed;
                }

                m_player.move(t_movement * dTime.asSeconds());
            }
        }

        /******************************************************************
        *                                                                 *
        * Render                                                          *
        *                                                                 *
        * Description:                                                    *
        *       Holders the items to draw on screen                       *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *       Clear the screen, and render objects                      *
        ******************************************************************/

        void Render()
        {
            m_window.clear();
            m_window.draw(m_player);
            m_window.display();
        }

        /******************************************************************
        *                                                                 *
        * handlePlayerInput                                               *
        *                                                                 *
        * Description:                                                    *
        *       Holders the items to draw on screen                       *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *       Clear the screen, and render objects                      *
        ******************************************************************/

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
        {
            if (key == sf::Keyboard::Up ||
                key == sf::Keyboard::W)
                {
                    m_moveUp = isPressed;
                }
            if (key == sf::Keyboard::Down ||
                key == sf::Keyboard::S)
                {
                    m_moveDown = isPressed;
                }
        }

};