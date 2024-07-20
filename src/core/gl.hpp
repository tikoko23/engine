#ifndef _GL_HPP
#define _GL_HPP

#include <GL/glx.h>

namespace Engine
{
    namespace Core
    {
        inline GLXContext gl_context;

        void init_opengl();

        void draw_gl();

        void end_opengl();
    }
}

#endif