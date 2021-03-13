#include <iostream>



/**
 * This class is a simple bare bones example showing use of a copy constructor
 * for the question on the exam.
 * 
 */
class RGBPallette
{
    protected:
        RgbColor *array;     // int pointer (dynamic memory)
        int size;       
    public:
        RGBPallette()
        {
            size = 100;
            array = new RgbColor[size];
        }
        RGBPallette(int s)
        {
            size = s;
            array = new RgbColor[size];
        }
        RGBPallette(const RGBPallette& other)
        {
            size = other.size;
            array = new RgbColor[size];
            for(int i=0;i<size;i++)
            {
                array[i] = other.array[i];
            }
        }
};


/**
 * This is an implementation of our single color rgb class. 
 * 
 */
class RgbColor
{
    protected:
        int r;                  //int 0-255 red
        int g;                  //int 0-255 green
        int b;                  //int 0-255 blue

    public: 
        RgbColor();             // default constructor
        RgbColor(int);          // overloaded 1
        RgbColor(int,int,int);  // overloaded 2

        void SetR(int);         // setter red
        void SetG(int);         // setter green
        void SetB(int);         // setter blue

        int GetR();             // getter red
        int GetG();             // getter green
        int GetB();             // getter blue

        void GrayScale();       // averages colors

        // print to stdout
        friend std::ostream& operator<<(std::ostream&,const RgbColor&);

        // add (mix) two colors
        RgbColor operator+(const RgbColor& );

};

RgbColor RgbColor::operator+(const RgbColor& rhs){
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

RgbColor::RgbColor(){
    r = g = b = 0;
}

RgbColor::RgbColor(int color){
    r = g = b = color;
}

RgbColor::RgbColor(int _r,int _g, int _b){
    r = _r;
    g = _g;
    b = _b;
}

std::ostream& operator<<(std::ostream& os,const RgbColor& rhs){
    os<<"["<<rhs.r<<","<<rhs.g<<","<<rhs.b<<"]";
    return os;
}