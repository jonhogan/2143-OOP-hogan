#include <iostream>
#include "rgbpallete.hpp"

int main()
{
    RGBColor Color1(255,200,11);
    RGBColor Color2(100,14,123);
    RGBColor Color3 = Color1 + Color2;
    RGBColor Color4;
    std::cout << "Color 4: " << Color4 << std::endl;
    Color4 = Color3;
    std::cout << "Color 3: " << Color3 << std::endl;
    std::cout << "Color 4: " << Color4 << std::endl;
    Color3.SetR(230);
    std::cout << "Color 3: " << Color3 << std::endl;
    std::cout << "Color 4: " << Color4 << std::endl;
}