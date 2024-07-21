#ifndef _OBJECTS_HPP
#define _OBJECTS_HPP

#include <vector>
#include <memory>

#include "../render/drawable.hpp"

namespace Engine
{
    namespace Core
    {
        inline std::vector<std::shared_ptr<Render::Drawable>> drawables;
    }
}

#endif