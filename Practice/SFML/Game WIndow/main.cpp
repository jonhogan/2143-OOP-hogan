#include <SFML/Graphics.hpp>

int main()
{
    /***********************************************************************
    ************************************************************************
    **                                                                    ** 
    ** You could used the "sf" namespace, but you might run into issues   **
    ** with conflicts                                                     **
    **                                                                    **
    ** I will use boxes like this to break down certain parts of the code **
    **                                                                    **
    ************************************************************************
    ***********************************************************************/

   // First you need to specify the game window:
   sf::RenderWindow window(sf::VideoMode(200,200), "Test Window", sf::Style::Default);

   /************************************************************************
   *************************************************************************
   **                                                                     **
   ** Breakdown:                                                          **
   **                                                                     **
   **  RenderWindow is a class reference that lets you make a... window.  **
   **  we named our RenderWindow variable 'window', but it could be       **
   **  called anything else. Three parameters are passed:                 **
   **                                                                     **
   **           VideoMode (another class reference):                      **
   **             Two were passed above: unsigned int Width and unisigned **
   **             int Height. There is a third one as well, unsigned int  **
   **             BitsPerPixel.                                           **
   **             Width: Width in pixels                                  **
   **             Height: Height in pixels                                **
   **             BitsPerPixels: Pixels depths in bits per pixel          **
   **                                                                     **
   **           The second is a const String used to title the window     **
   **                                                                     **
   **           The last one we passed is Style. We used Default which    **
   **           adds a maximize, minimize, and close button to the title  **
   **           bar.                                                      **
   **                                                                     **
   *************************************************************************
   ************************************************************************/

   // Create a shape to be drawn in our window
   sf::CircleShape shape(100.f);

   /************************************************************************
   *************************************************************************
   ** Breakdown:                                                          **
   **                                                                     **
   ** This is the Circleshape class, you will name your variable ('shape' **
   ** in this case), you will pass through a float variable to set the    **
   ** radius                                                              **
   **                                                                     **
   *************************************************************************
   ************************************************************************/

   // Give your shape a color
   shape.setFillColor(sf::Color::Green);

   /************************************************************************
   *************************************************************************
   ** Breakdown:                                                          **
   **                                                                     **
   ** In this one, we call the setFillColor method, and pass through a    **
   ** class refernce. In this case we passed though a pre set color.      **
   **                                                                     **
   *************************************************************************
   ************************************************************************/

   // We have set up a Window, created an object to drawn, and given it a
   // color. Now on to the main part of the program.. the window loop

   while(window.isOpen())
   {
        /***********************************************************************
        ************************************************************************
        ** Breakdown:                                                         **
        **                                                                    **
        ** Just a simple one, calls the isOpen method to returns a bool       **
        **                                                                    **
        ************************************************************************
        ***********************************************************************/

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            /*******************************************************************
            ******************************************************************** 
            **                                                                **
            **  A lot here, so straight from sfml-dev.org:                    **
            **                                                                **
            **  Defines a system event and its parameters.                    **
            **  sf::Event holds all the informations about a system event     **     
            **  that just happened.                                           **
            **                                                                **
            **  Events are retrieved using the sf::Window::pollEvent and      **
            **  sf::Window::waitEvent functions.                              **
            **                                                                **
            **  A sf::Event instance contains the type of the event (mouse    **
            **  moved, key pressed, window closed, ...) as well as the        **
            **  details about this particular event. Please note that the     **
            **  event parameters are defined in a union, which means that     **
            ** only the member matching the type of the event will be         **
            ** properly filled; all other members will have undefined values  **
            ** and must not be read if the type of the event doesn't match.   **
            ** For example, if you received a KeyPressed event, then you      **
            ** must read the event.key member, all other members such as      **
            ** event.mouseMove or event.text will have undefined values.      **
            **                                                                **
            ********************************************************************
            *******************************************************************/
    
        }
        
        window.clear();         // clears the window               
        window.draw(shape);     // draw out shape object
        window.display();
    }
 /*
 * To compile:
 *  g++ -c main.cpp
 *  g++ main.o -o <name> -lsfml-graphics -lsfml-window -lsfml-system
 *  ./<name>
 */
 return 0;
}