#ifndef _VECTOR2_HPP
#define _VECTOR2_HPP

#include <iostream>

namespace Engine
{
    struct Vector2
    {
        double x;
        double y;

        Vector2(double x, double y);
        Vector2();

        Vector2 operator+(const Vector2& v);

        Vector2 operator-(const Vector2& v);

        Vector2 operator*(const Vector2& v);

        Vector2 operator/(const Vector2& v);

        friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }

        double magnitude();

        double magnitude_sqr();
    };
}

#endif