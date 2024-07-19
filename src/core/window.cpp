#ifndef _WINDOW_CPP
#define _WINDOW_CPP

#include <X11/Xlib.h>
#include "../util/logger.hpp"
#include "../types/vector2i.hpp"

namespace Engine
{
    namespace Core
    {
        inline Display *current_display = XOpenDisplay(NULL);
        inline Window active_window = None;

        void init_window(
            int pos_x = 0, int pos_y = 0,
            unsigned int size_x = 800, unsigned int size_y = 800,
            unsigned int border_width = 0, unsigned long border = 0,
            unsigned int bg_color = 0xffffffff
        )
        {
            Logger::assert(current_display != NULL, "Failed to initialise display\n");

            Window root_window = DefaultRootWindow(current_display);

            Logger::assert(root_window != None, "No root window found\n", true, true, [](){XCloseDisplay(current_display);});

            active_window = XCreateSimpleWindow(
                current_display,
                root_window,
                pos_x, pos_y,
                size_x, size_y,
                border_width, border,
                bg_color
            );

            Logger::assert(active_window != None, "Failed to create window\n", true, true, [](){XCloseDisplay(current_display);});

            XMapWindow(current_display, active_window);

            Atom wm_delete_window = XInternAtom(current_display, "WM_DELETE_WINDOW", False);
            XSetWMProtocols(current_display, active_window, & wm_delete_window, 1);
        }
    }
}

#endif