#include <SFML/Graphics.hpp>
#include <iostream>




//https://en.sfml-dev.org/forums/index.php?topic=12278.0




class PLAYER : public sf::Drawable
{
    private:
        sf::CircleShape *circle;    // reference to our "player"
        float x;                      // x location
        float y;                      // y location
        float dx;                     // "change" in x
        float dy;                     // "change" in y
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
            target.draw(*circle, states);
        }

    public:
        PLAYER(int w,int h, float r)
        {

            width = w;          // window size
            height = h;
            radius = r;
            x = 60;  // location
            y = 240;
            
            // define a circle with radius = 200
            circle = new sf::CircleShape(radius);

                circle->setFillColor(sf::Color(76, 0, 153, 255));     //

            // set the radius to whatever
            circle->setRadius(radius);

            // change the number of sides (points) to 100
            circle->setPointCount(100);

            circle->setPosition(sf::Vector2f(x, y));
        }


      void moveUp(float vert)
        {
            if(y > 0)
            {
                y += vert;
                circle->setPosition(sf::Vector2f(x, y));
            }
        }
        void moveDown(float vert)
        {
            if(y < (height - (radius * 2)))
            {
                y += vert;
                circle->setPosition(sf::Vector2f(x, y));
            }
        }
};