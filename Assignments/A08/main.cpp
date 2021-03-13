#include <iostream>
#include "rgbpallete.hpp"

int main()
{
    RgbColor Color1(255,200,11);
    RgbColor Color2(100,14,123);
    RgbColor Color3 = Color1 + Color2;
    std::cout<<Color3<<std::endl;
}