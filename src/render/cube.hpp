#ifndef _CUBE_HPP
#define _CUBE_HPP

#include "../types/vector3.hpp"
#include "../types/vector2.hpp"
#include "../def/prismtemplates.hpp"
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

            void draw(int draw_type) override
            {
                std::vector<Vector3> vertices;

                switch (draw_type)
                {
                  case GL_POINTS:
                    vertices = std::vector<Vector3>(Templates::cube_points.begin(), Templates::cube_points.end());
                    break;
                  case GL_LINES:
                    vertices = std::vector<Vector3>(Templates::cube_lines.begin(), Templates::cube_lines.end());
                }

                for (const auto& vert : vertices)
                {
                    Vector3 sized_vert = Vector3(vert);

                    sized_vert = Math::rotate_xyz(sized_vert, rotation);

                    sized_vert = position + sized_vert * size;

                    Vector2 p = Math::project_to_screen(sized_vert, 800);
                    p = Math::to_screen_coords(p);
                    glVertex2f(p.x, p.y);
                }
            }
        };
    }
}

#endif