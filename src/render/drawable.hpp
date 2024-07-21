#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include "../types/vector3.hpp"
#include "../util/logger.hpp"

namespace Engine
{
    namespace Render
    {
        struct Drawable
        {
            Vector3 position;
            Vector3 rotation;

            virtual void draw(int draw_type)
            {
                Logger::warn("Render::Drawable is a base class. Override the draw method on the inherited object\n");
            }
        };
    }
}

#endif