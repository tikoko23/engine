#ifndef _VECTOR2I_HPP
#define _VECTOR2I_HPP

#include <iostream>
#include <cmath>

namespace Engine
{
    struct Vector2i
    {
        int x;
        int y;

        Vector2i(int x, int y);
        Vector2i();

        Vector2i operator+(const Vector2i& v);

        Vector2i operator-(const Vector2i& v);

        Vector2i operator*(const Vector2i& v);

        Vector2i operator/(const Vector2i& v);

        friend std::ostream& operator<<(std::ostream& os, const Vector2i& v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }

        double magnitude();

        double magnitude_sqr();
    };
}

#endif