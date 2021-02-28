#include <SFML/Graphics.hpp>
#include <iostream>

//https://en.sfml-dev.org/forums/index.php?topic=12278.0
class PLAYER : public sf::Drawable {
public:
    PLAYER(int w,int h) {

        width = w;          // window size
        height = h;
        dx = -1;            // direction
        dy = -1;
        x = (rand() % int(width));  // location
        y = (rand() % int(height));
        d = .1;             // distance

        // define a circle with radius = 200
        circle = new sf::CircleShape(20.f);

        circle->setFillColor(sf::Color::Green);

        // set the radius to whatever
        circle->setRadius(20.f);

        // change the number of sides (points) to 100
        circle->setPointCount(100);

        circle->setPosition(sf::Vector2f(x, y));


    }


    void update(){

        position = circle->getPosition();
        bool hit = false;

        if(position.x >= width)
        {
            dx = dx * -1;
            hit = true;
        }

        if(position.y >= height)
        {
            dy = dy * -1;
            hit = true;
        }

        if(position.x < 0)
        {
            dx = dx * -1;
            hit = true;
        }

        if(position.y < 0)
        {
            dy = dy * -1;
            hit = true;
        }

        x = position.x + (d * dx);
        y = position.y + (d * dy);

        circle->setPosition(sf::Vector2f(x, y));

    }

private:
    sf::CircleShape *circle;    // reference to our "ball"
    float x;                      // x location
    float y;                      // y location
    float dx;                     // "change" in x
    float dy;                     // "change" in y
    float width;
    float height;
    float d;                    // distance to move
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
};