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

        const Vector3 to_const();

        const Vector3 operator+(const Vector3& v);

        const Vector3 operator-(const Vector3& v);

        const Vector3 operator*(const Vector3& v);
        const Vector3 operator*(const double& d);

        const Vector3 operator/(const Vector3& v);

        bool operator<(const Vector3& _v);
        
        bool operator>(const Vector3& _v);

        bool operator==(const Vector3& v);

        friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
        {
            os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
            return os;
        }

        double magnitude();

        double magnitude_sqr();
    };
}

#endif