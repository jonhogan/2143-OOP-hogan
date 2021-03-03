#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>




//https://en.sfml-dev.org/forums/index.php?topic=12278.0




class PLAYER : public sf::Drawable
{
    private:
        sf::CircleShape *circle;    // reference to our "player"
        float x;                      // x location
        float y;                      // y location
        float width;
        float height;
        float radius;
        sf::Vector2f position;
        
        /**
        * virtual = A virtual function a member function which is declared within base class and is re-defined (Overriden) by derived class.
        * function draw:
        *     draw an SFML object to some window
        */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(*circle, states);
        }

    public:
        PLAYER(int w,int h, float r)
        {

            width = w;          // window size
            height = h;
            radius = r;
            x = 60;  // location
            y = (width/3);
            
            // define a circle with radius = 200
            circle = new sf::CircleShape(radius);

            circle->setFillColor(sf::Color(76, 0, 153, 255));     //

            // set the radius to whatever
            circle->setRadius(radius);

            // change the number of sides (points) to 100
            circle->setPointCount(100);

            circle->setPosition(sf::Vector2f(x, y));
        }


        void moveUp(float dy)
        {
            if(y > 0)
            {
                y += dy;
                circle->setPosition(sf::Vector2f(x, y));
            }
        }
        void moveDown(float dy)
        {
            if(y < (height - (radius * 2)))
            {
                y += dy;
                circle->setPosition(sf::Vector2f(x, y));
            }
        }
};

class DEBRIS : public sf::Drawable
{
    private:
        sf::RectangleShape *rectangle;    // reference to our "player"
        float x;                      // x location
        float y;                      // y location
        float width;
        float height;
        float d;                    // distance to move
        float radius;
        sf::Vector2f position;
        
        /**
        * virtual = A virtual function a member function which is declared within base class and is re-defined (Overriden) by derived class.
        * function draw:
        *     draw an SFML object to some window
        */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(*rectangle, states);
        }

    public:
        DEBRIS()
        {

            width = 300;          // window size
            height = 300;
            x = width;  // location
            y = rand() % 300;
            
            // define a rectangle
            rectangle = new sf::RectangleShape (sf::Vector2f(15,15));
            rectangle->setFillColor(sf::Color(rand()%255, rand()%255, rand()%255, 255));     //
            rectangle->setPosition(sf::Vector2f(width, y));
        }
        DEBRIS(int w,int h)
        {

            width = w;          // window size
            height = h;
            x = w;  // location
            y = rand() % h;
            
            // define a rectangle
            rectangle = new sf::RectangleShape (sf::Vector2f(15,15));
            rectangle->setFillColor(sf::Color(rand()%255, rand()%255, rand()%255, 255));     //
            rectangle->setPosition(sf::Vector2f(width, y));
        }


      void move(float dx)
        {
            if(x > 0)
            {
                x += dx;
                rectangle->setPosition(sf::Vector2f(x, y));
            }
        }
};