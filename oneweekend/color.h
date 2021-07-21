/******************************************************************
** color.h
** @Author       : BanMing 
** @Date         : 7/21/2021, 11:06:04 PM
** @Description  : 
*******************************************************************/

#ifndef Color_H
#define Color_H

#include <iostream>

#include "vec3.h"

void write_color(std::ostream &out, color pixel_color)
{
    // Write the translated [0,255] value of each color component
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

#endif