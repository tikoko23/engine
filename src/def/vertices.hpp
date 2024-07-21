#ifndef _VERTICES_HPP
#define _VERTICES_HPP

#include <array>

#include "../types/vector3.hpp"

namespace Engine
{
    namespace Render
    {
        namespace Vertices
        {
            inline const std::array<Vector3, 8> cube = {
                Vector3(-1, -1, 1),
                Vector3(1, -1, 1),
                Vector3(1, 1, 1),
                Vector3(-1, 1, 1),
                Vector3(-1, -1, -1),
                Vector3(1, -1, -1),
                Vector3(1, 1, -1),
                Vector3(-1, 1, -1)
            };
        }
    }
}

#endif