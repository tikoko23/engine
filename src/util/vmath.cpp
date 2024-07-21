#ifndef _VMATH_CPP
#define _VMATH_CPP

#include "../types/vector2.hpp"
#include "../types/vector3.hpp"
#include "../core/window.hpp"

namespace Engine
{
    namespace Math
    {
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
    }
}

#endif