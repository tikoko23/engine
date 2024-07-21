#ifndef _CUBE_HPP
#define _CUBE_HPP

#include "../types/vector3.hpp"
#include "../types/vector2.hpp"
#include "../def/vertices.hpp"
#include "../util/vmath.hpp"
#include "drawable.hpp"

namespace Engine
{
    namespace Render
    {
        struct Cube : public Drawable
        {
            Vector3 position;
            Vector3 size;
            Vector3 rotation;

            Cube()
            {
                this->position = Vector3();
                this->rotation = Vector3();
                this->size = Vector3(50, 50, 50);
            }

            void draw() override
            {
                for (const auto& vert : Vertices::cube)
                {
                    Vector3 sized_vert = Vector3(vert);

                    sized_vert = position + sized_vert * size;

                    Vector2 p = Math::project_to_screen(sized_vert, 90);
                    p = Math::to_screen_coords(p);
                    glVertex2f(p.x, p.y);
                }
            }
        };
    }
}

#endif