#include <iostream>



/**
* This is an implementation of our single color rgb class. 
* 
*/

class RGBColor
{
    protected:
        int r;                  //int 0-255 red
        int g;                  //int 0-255 green
        int b;                  //int 0-255 blue

    public: 
        RGBColor()             // default constructor
        {
            r = g = b = 0;
        }

        RGBColor(int color)           // overloaded 1
        {
            r = g = b = color;
        }

        RGBColor(int red, int green, int blue)   // overloaded 2
        {
            r = red;
            g = green;
            b = blue;
        }

        void SetR(int _r)       // setter red
        {
            r = _r;
        }

        void SetG(int _g)       // setter green
        {
            g =_g;
        }

        void SetB(int _b)       // setter blue
        {
            b = _b;
        }

        int GetR()              // getter red
        {
            return r;
        }

        int GetG()              // getter green
        {
            return g;
        }

        int GetB()              // getter blue
        {
            return b;
        }

        std::string GetRGB()    // Get RGB String
        {
            std::string rgb = "[" + r + ' ' + ',' + g + ' ' + ',' + b + ']';
            return rgb;

        }

        void GrayScale()        // averages colors
        {
            int gray;
            gray = (r + g + b)/3;
            r = g = b = gray;
        }

        // print to stdout
        friend std::ostream& operator<<(std::ostream& os,const RGBColor& rhs)
        {
            os<<"["<<rhs.r<<","<<rhs.g<<","<<rhs.b<<"]";
            return os;     
        }

        // add (mix) two colors
        RGBColor operator+(const RGBColor& rhs)
        {
            int r = (this->r + rhs.r) / 2;
            int g = (this->g + rhs.g) / 2;
            int b = (this->b + rhs.b) / 2;
            
            return *this;
        }

        RGBColor operator=(const RGBColor& rhs)
        {
            this -> r = rhs.r;
            this -> g = rhs.g;
            this -> b = rhs.b;

            return *this;
        }

};

/**
 * This class is a simple bare bones example showing use of a copy constructor
 * for the question on the exam.
 * 
 */
class RGBPallette
{
    protected:
        RGBColor *array;     // int pointer (dynamic memory)
        int size;      
        int top =0; 
    public:
        RGBPallette()
        {
            size = 100;
            array = new RGBColor[size];
        }
        RGBPallette(int s)
        {
            size = s;
            array = new RGBColor[size];
        }
        RGBPallette(const RGBPallette& other)
        {
            size = other.size;
            array = new RGBColor[size];
            for(int i=0;i<size;i++)
            {
                array[i] = other.array[i];
            }
        }


        /**************************************************************
        * Public void: RGBCopy
        *
        * Descriptions:
        *         makes a copy of the array
        * Params:
        *         NULL
        * Returns:
        *         NULL
        **************************************************************/
        void RGBCopy()
        {
            RGBColor* B = new RGBColor[size];      // New memory

            for (int i = 0; i < size; i++) // Copy data to new stack
            {
                B[i] = array[i];
            }

            delete[] array;                      // Delete old array
            array = B;                           // Reset the pointer
        }

        /**************************************************************
        * Public void: Print
        *
        * Descriptions:
        *         Prints out the array
        * Params:
        *         NULL
        * Returns:
        *         NULL
        **************************************************************/
        void Print()
        {
            for (int i = 0; i < top; i++)
            {
                std::cout << array[i].GetRGB() << ", ";
            }
            std::cout << std::endl;
        }

        /**************************************************************
        * Public Push
        *
        * Description:
        *         Add RGBColor to the top of the array
        *
        * Params:
        *         [RGBColor]: Data to add
        *
        * Returns:
        *         Null
        **************************************************************/

        void Push(RGBColor x)
        {
            if ((top + 1) == size)             // Increase stack size if full
            {
                std::cout << "ERROR: Array is full" << std::endl;
            }else
            {
                array[++top] = x;
            }
        }
};