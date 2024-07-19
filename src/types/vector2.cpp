#ifndef _VECTOR2_CPP
#define _VECTOR2_CPP

#include <iostream>

namespace Engine
{
    struct Vector2
    {
        double x;
        double y;

        Vector2(double x, double y)
        {
            this->x = x;
            this->y = y;
        }

        Vector2 operator+(const Vector2& v)
        {
            return Vector2(this->x + v.x, this->y + v.y);
        }

        Vector2 operator-(const Vector2& v)
        {
            return Vector2(this->x - v.x, this->y - v.y);
        }

        Vector2 operator*(const Vector2& v)
        {
            return Vector2(this->x * v.x, this->y * v.y);
        }

        Vector2 operator/(const Vector2& v)
        {
            return Vector2(this->x / v.x, this->y / v.y);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector2& v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };
}

#endif