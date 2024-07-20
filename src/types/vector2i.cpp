#ifndef _VECTOR2I_CPP
#define _VECTOR2I_CPP

#include <iostream>

#include "vector2i.hpp"

namespace Engine
{
    Vector2i::Vector2i(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2i::Vector2i()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2i Vector2i::operator+(const Vector2i& v)
    {
        return Vector2i(this->x + v.x, this->y + v.y);
    }

    Vector2i Vector2i::operator-(const Vector2i& v)
    {
        return Vector2i(this->x - v.x, this->y - v.y);
    }

    Vector2i Vector2i::operator*(const Vector2i& v)
    {
        return Vector2i(this->x * v.x, this->y * v.y);
    }

    Vector2i Vector2i::operator/(const Vector2i& v)
    {
        return Vector2i(this->x / v.x, this->y / v.y);
    }

    double Vector2i::magnitude()
    {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }

    double Vector2i::magnitude_sqr()
    {
        return this->x * this->x + this->y * this->y;
    }
}

#endif