#ifndef _VMATH_CPP
#define _VMATH_CPP

#include "../types/vector2.hpp"
#include "../types/vector3.hpp"

namespace Engine
{
    namespace Math
    {
        Vector2 project_to_screen(Vector3 point, float fov);

        Vector2 to_screen_coords(Vector2 point);
    }
}

#endif