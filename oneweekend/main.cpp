/******************************************************************
** main.cpp
** @Author       : BanMing 
** @Date         : 7/21/2021, 9:29:55 PM
** @Description  : 
*******************************************************************/
#include <iostream>

#include "vec3.h"
#include "color.h"

int main()
{
    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i)
    {
        std::cerr << "\r Scanlines remaining:" << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j)
        {
            color pixel_color(float(i) / (image_width - 1), float(j) / (image_height - 1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}