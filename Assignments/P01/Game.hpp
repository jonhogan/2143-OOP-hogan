#include <SFML/Graphics.hpp>
#include <iostream>



//https://en.sfml-dev.org/forums/index.php?topic=12278.0




class PLAYER : public sf::Drawable
{
     private:
        sf::CircleShape *circle;    // reference to our "ball"
        float x;                      // x location
        float y;                      // y location
        float dx;                     // "change" in x
        float dy;                     // "change" in y
        float width;
        float height;
        float d;                    // distance to move
        int red;
        int blue;
        int green;
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
        PLAYER(int w,int h)
        {

            width = w;          // window size
            height = h;
            dx = -1;            // direction
            dy = -1;
            x = 60;  // location
            y = 240;
            d = .1;             // distance

            // define a circle with radius = 200
            circle = new sf::CircleShape(5.f);

            red = (rand()%255);                                         //
            green = (rand()%255);                                       //  Randomly assigns a color
            blue = (rand()%255);                                        //  to the player object
                                                                    //  
            circle->setFillColor(sf::Color(red, green, blue, 255));     //

            // set the radius to whatever
            circle->setRadius(20.f);

            // change the number of sides (points) to 100
            circle->setPointCount(100);

            circle->setPosition(sf::Vector2f(x, y));
        }


      void move(float vert)
        {
            y += vert;
            circle->setPosition(sf::Vector2f(x, y));
        }
};