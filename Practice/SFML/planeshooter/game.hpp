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
*       sf::RenderWindow mWindow; Game window                         *
*       sf::CircleShape mPlayer;  Player object                       *
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
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;

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
        GAME(): mWindow(
            sf::VideoMode(640,480), "Game Window",
            sf::Style::Default), mPlayer()
        {
            mPlayer.setRadius(40.f);
            mPlayer.setPosition(100.f, 100.f);
            mPlayer.setFillColor(sf::Color(76, 0, 153, 255));
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
            while (mWindow.isOpen())
            {
                ProcessEvents();
                Update();
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
         while (mWindow.pollEvent(event)) 
            {
                switch(event.type)
                {
                    case sf::Event::KeyPressed:
                         handlePlayerInput(event.key.code, true);
                         break;
                    case sf::Event::KeyReleased:
                         handlePlayerInput(event.key.code, false);
                         break;
                }
                        
            }
        }
        

        /******************************************************************
        *                                                                 *
        * Update                                                          *
        *                                                                 *
        * Description:                                                    *
        *                                                                 *
        *                                                                 *
        * Method Variables:                                               *
        *                                                                 *
        * Use:                                                            *
        *                                                                 *
        ******************************************************************/

        void Update()
        {

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
            mWindow.clear();
            mWindow.draw(mPlayer);
            mWindow.display();
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
                    mIsMovingUp = isPressed;
                }else if (key == sf::Keyboard::Down ||
                key == sf::Keyboard::S)
                {
                    mIsMovingDown = isPressed;
                }
        }

};