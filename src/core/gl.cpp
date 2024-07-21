#ifndef _GL_CPP
#define _GL_CPP

#include <sstream>
#include <GL/glx.h>

#include "window.hpp"
#include "time.hpp"
#include "../render/cube.hpp"
#include "objects.hpp"
#include "../util/vmath.hpp"
#include "../util/logger.hpp"
#include "../types/vector3.hpp"

namespace Engine
{
    namespace Core
    {
        inline GLXContext gl_context = None;

        void init_opengl()
        {
            Logger::assert(active_window != None, "A window must be initialised first\n");
            Logger::log("Starting OpenGL context...\n");
            
            gl_context = glXCreateContext(current_display, visual_info, NULL, true);
            
            Logger::assert(gl_context != None, "Failed to create context\n");
            Logger::log("Started context.\n");
            Logger::log("Activating context...\n");

            glXMakeCurrent(current_display, active_window, gl_context);

            Logger::log("Activated context.\n");

            std::stringstream gl_info_text;
            gl_info_text << "GL Vendor: " << glGetString(GL_VENDOR) << '\n';
            gl_info_text << "GL Renderer: " << glGetString(GL_RENDERER) << '\n';
            gl_info_text << "GL Version: " << glGetString(GL_VERSION) << '\n';
            gl_info_text << "GL Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';

            Logger::log_gl(gl_info_text.str(), false);
        }

        void draw_gl()
        {
            auto start_time = hr_clock.now();

            glClear(GL_COLOR_BUFFER_BIT);

            glBegin(GL_LINES);

            glColor3f(1, 1, 1);

            for (auto& obj : Core::drawables)
            {
                obj->draw(GL_LINES);
            }
            
            glEnd();

            glXSwapBuffers(current_display, active_window);

            auto duration = hr_clock.now() - start_time;
            delta_time = std::chrono::duration<double>(duration).count();
        }

        void end_opengl()
        {
            Logger::log("Closing OpenGL context...\n");
            glXDestroyContext(current_display, gl_context);
            XFree(visual_info);
            XFreeColormap(current_display, gl_colormap);
        }
    }
}

#endif