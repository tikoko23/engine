#ifndef _VMATH_CPP
#define _VMATH_CPP

#include <cmath>

#include "../types/vector2.hpp"
#include "../types/vector3.hpp"
#include "../core/window.hpp"

namespace Engine
{
    namespace Math
    {
        inline const double deg_to_rad = M_PI / 180;
        inline const double rad_to_deg = 180 / M_PI;

        Vector2 project_to_screen(Vector3 point, float fov)
        {
            float d = point.z + fov;
            return Vector2(
                point.x * fov / d,
                point.y * fov / d
            );
        }

        Vector2 to_screen_coords(Vector2 point)
        {
            return point / Core::window_size;
        }

        Vector3 rotate_x(Vector3 p, double angle)
        {
            double cos_a = std::cos(angle);
            double sin_a = std::sin(angle);
            return Vector3(
                p.x,
                p.y * cos_a + p.z * sin_a,
                p.z * cos_a - p.y * sin_a
            );
        }

        Vector3 rotate_y(Vector3 p, double angle)
        {
            double cos_a = std::cos(angle);
            double sin_a = std::sin(angle);
            return Vector3(
                p.x * cos_a - p.z * sin_a,
                p.y,
                p.x * sin_a + p.z * cos_a
            );
        }

        Vector3 rotate_z(Vector3 p, double angle)
        {
            double cos_a = std::cos(angle);
            double sin_a = std::sin(angle);
            return Vector3(
                p.x * cos_a + p.y * sin_a,
                p.y * cos_a - p.x * sin_a,
                p.z
            );
        }

        Vector3 rotate_xyz(Vector3 p, Vector3 a)
        {
            return rotate_z(rotate_y(rotate_x(p, a.x), a.y), a.z);
        }
    }
}

#endif