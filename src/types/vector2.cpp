#ifndef _VECTOR2_CPP
#define _VECTOR2_CPP

#include <iostream>
#include <cmath>

#include "vector2.hpp"

namespace Engine
{
    Vector2::Vector2(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2::Vector2()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2 Vector2::operator+(const Vector2& v)
    {
        return Vector2(this->x + v.x, this->y + v.y);
    }

    Vector2 Vector2::operator-(const Vector2& v)
    {
        return Vector2(this->x - v.x, this->y - v.y);
    }

    Vector2 Vector2::operator*(const Vector2& v)
    {
        return Vector2(this->x * v.x, this->y * v.y);
    }

    Vector2 Vector2::operator/(const Vector2& v)
    {
        return Vector2(this->x / v.x, this->y / v.y);
    }

    double Vector2::magnitude()
    {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }

    double Vector2::magnitude_sqr()
    {
        return this->x * this->x + this->y * this->y;
    }
}

#endif