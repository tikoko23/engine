#ifndef _WINDOW_CPP
#define _WINDOW_CPP

#include <X11/Xlib.h>
#include <GL/glx.h>

#include "../util/logger.hpp"
#include "../types/vector2.hpp"

namespace Engine
{
    namespace Core
    {
        inline Display *current_display = XOpenDisplay(NULL);
        inline Window active_window = None;
        inline Vector2 window_size = Vector2(0, 0);
        inline XVisualInfo* visual_info = None;
        inline Colormap gl_colormap = None;

        void init_window(
            int pos_x = 0, int pos_y = 0,
            unsigned int size_x = 800, unsigned int size_y = 800,
            unsigned int border_width = 0
        )
        {
            Logger::assert(current_display != NULL, "Failed to initialise display\n");
            Logger::log("Initialised display\n");

            GLint glxAttribs[] = {
                GLX_RGBA,
                GLX_DOUBLEBUFFER,
                GLX_DEPTH_SIZE,     24,
                GLX_STENCIL_SIZE,   8,
                GLX_RED_SIZE,       8,
                GLX_GREEN_SIZE,     8,
                GLX_BLUE_SIZE,      8,
                GLX_SAMPLE_BUFFERS, 0,
                GLX_SAMPLES,        0,
                None
            };

            int screen = DefaultScreen(current_display);

            visual_info = glXChooseVisual(current_display, screen, glxAttribs);

            Logger::assert(visual_info != None, "Could not create OpenGL visual\n", true, true, [](){
                XCloseDisplay(current_display);
            });

            Window root_window = DefaultRootWindow(current_display);

            Logger::assert(root_window != None, "No root window found\n", true, true, [](){XCloseDisplay(current_display);});
            Logger::log("Detected root window\n");

            XSetWindowAttributes attribs;
            attribs.border_pixel = BlackPixel(current_display, screen),
            attribs.background_pixel = WhitePixel(current_display, screen),
            attribs.override_redirect = true,
            attribs.colormap = XCreateColormap(current_display, root_window, visual_info->visual, AllocNone);
            attribs.event_mask = ExposureMask;

            gl_colormap = attribs.colormap;

            active_window = XCreateWindow(
                current_display, root_window,
                pos_x, pos_y,
                size_x, size_y,
                border_width,
                visual_info->depth,
                InputOutput,
                visual_info->visual,
                CWBackPixel | CWColormap | CWBorderPixel | CWEventMask,
                &attribs
            );

            window_size = Vector2(size_x, size_y);

            Logger::assert(active_window != None, "Failed to create window\n", true, true, [](){XCloseDisplay(current_display);});
            Logger::log("Created window\n");

            XMapWindow(current_display, active_window);
            XMapRaised(current_display, active_window);
        }

        void end_window()
        {
            Logger::log("Closing window\n");
            XDestroyWindow(current_display, active_window);
            Logger::log("Closing display\n");
            XCloseDisplay(current_display);
        }
    }
}

#endif