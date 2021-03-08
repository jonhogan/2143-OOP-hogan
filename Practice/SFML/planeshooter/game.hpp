#include <SFML/Graphics.hpp>

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
*       sf::RenderWindow window; Game window                         *
*       sf::CircleShape player;  Player object                       *
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

class GAME
{
    protected:
        const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
        const float pSpeed = 100.f;

        sf::RenderWindow window;
        sf::CircleShape player;

        bool isMovingUp = false;
        bool isMovingDown = false;

    public:

        /******************************************************************
        *                                                                 *
        * GAME                                                            *
        *                                                                 *
        * Description:                                                    *
        *       Holds the game window, player object and anyother objects *
        *       in game.                                                  *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *   Creates our game object                                       *
        *                                                                 *
        ******************************************************************/
        GAME(): window(
            sf::VideoMode(640,480), "Game Window",
            sf::Style::Default), player()
        {
            player.setRadius(15.f);
            player.setPosition(100.f, 200.f);
            player.setFillColor(sf::Color(76, 0, 153, 255));
        }

        /******************************************************************
        *                                                                 *
        * Run                                                             *
        *                                                                 *
        * Description:                                                    *
        *       Holds the window while loop.                              *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *   Runs the processes to run the game whilewindow.isOpen = true  *
        *                                                                 *
        ******************************************************************/

        void Run()
        {
            sf::Clock clock;

            /*

                Implementing fixed time steps.

                Helps to solve issues with lag. This will help prevent
                colliding objects from passing through eachother

            */

            sf::Time lastUpdate = sf::Time::Zero;

            while (window.isOpen())
            {
                ProcessEvents();
                lastUpdate += clock.restart();
                while (lastUpdate > TimePerFrame)
                {
                    lastUpdate -= TimePerFrame;
                    ProcessEvents();
                    Update(TimePerFrame);
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
         while (window.pollEvent(event)) 
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
                        window.close();
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
            sf::Vector2f movement(0.f, 0.f);
            if (player.getPosition().y >= 0)
            {
                if(isMovingUp)
                {
                    movement.y -= pSpeed;
                }
                player.move(movement * dTime.asSeconds());
            }
            if (player.getPosition().y <= 450)
            {
                if(isMovingDown)
                {
                    movement.y += pSpeed;
                }

                player.move(movement * dTime.asSeconds());
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
            window.clear();
            window.draw(player);
            window.display();
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
                    isMovingUp = isPressed;
                }
            if (key == sf::Keyboard::Down ||
                key == sf::Keyboard::S)
                {
                    isMovingDown = isPressed;
                }
        }

};