#ifndef _VMATH_CPP
#define _VMATH_CPP

#include <cmath>

#include "../types/vector2.hpp"
#include "../types/vector3.hpp"

namespace Engine
{
    namespace Math
    {
        inline const double deg_to_rad = M_PI / 180;
        inline const double rad_to_deg = 180 / M_PI;

        Vector2 project_to_screen(Vector3 point, float fov);

        Vector2 to_screen_coords(Vector2 point);

        Vector3 rotate_x(Vector3 p, double angle);
        Vector3 rotate_y(Vector3 p, double angle);
        Vector3 rotate_z(Vector3 p, double angle);

        Vector3 rotate_xyz(Vector3 p, Vector3 a);
    }
}

#endif