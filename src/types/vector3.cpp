#ifndef _VECTOR2_CPP
#define _VECTOR2_CPP

#include <iostream>
#include <cmath>

#include "vector3.hpp"

namespace Engine
{
    Vector3::Vector3(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3::Vector3()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector3 Vector3::operator+(const Vector3& v)
    {
        return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
    }

    Vector3 Vector3::operator-(const Vector3& v)
    {
        return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
    }

    Vector3 Vector3::operator*(const Vector3& v)
    {
        return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
    }

    Vector3 Vector3::operator/(const Vector3& v)
    {
        return Vector3(this->x / v.x, this->y / v.y, this->z / v.z);
    }

    double Vector3::magnitude()
    {
        return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    double Vector3::magnitude_sqr()
    {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }
}

#endif