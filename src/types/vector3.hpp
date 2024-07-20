#ifndef _VECTOR3_HPP
#define _VECTOR3_HPP

#include <iostream>

namespace Engine
{
    struct Vector3
    {
        double x;
        double y;
        double z;

        Vector3(double x, double y, double z);
        Vector3();

        Vector3 operator+(const Vector3& v);

        Vector3 operator-(const Vector3& v);

        Vector3 operator*(const Vector3& v);

        Vector3 operator/(const Vector3& v);

        friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }

        double magnitude();

        double magnitude_sqr();
    };
}

#endif