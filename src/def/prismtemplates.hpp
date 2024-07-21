#ifndef _VERTICES_HPP
#define _VERTICES_HPP

#include <array>

#include "../types/vector3.hpp"

namespace Engine
{
    namespace Render
    {
        namespace Templates
        {
            inline const std::array<Vector3, 8> cube_points = {
                Vector3(-1, -1, 1),
                Vector3(1, -1, 1),
                Vector3(1, 1, 1),
                Vector3(-1, 1, 1),
                Vector3(-1, -1, -1),
                Vector3(1, -1, -1),
                Vector3(1, 1, -1),
                Vector3(-1, 1, -1)
            };

            inline const std::array<Vector3, 24> cube_lines = {
                Vector3(-1, -1, 1),
                Vector3(1, -1, 1),
                Vector3(1, -1, 1),
                Vector3(1, 1, 1),
                Vector3(1, 1, 1),
                Vector3(-1, 1, 1),
                Vector3(-1, 1, 1),
                Vector3(-1, -1, 1),
                Vector3(-1, -1, -1),
                Vector3(1, -1, -1),
                Vector3(1, -1, -1),
                Vector3(1, 1, -1),
                Vector3(1, 1, -1),
                Vector3(-1, 1, -1),
                Vector3(-1, 1, -1),
                Vector3(-1, -1, -1),
                Vector3(-1, -1, 1),
                Vector3(-1, -1, -1),
                Vector3(1, -1, 1),
                Vector3(1, -1, -1),
                Vector3(1, 1, 1),
                Vector3(1, 1, -1),
                Vector3(-1, 1, 1),
                Vector3(-1, 1, -1),
            };
        }
    }
}

#endif