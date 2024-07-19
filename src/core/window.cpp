#ifndef _WINDOW_CPP
#define _WINDOW_CPP

#include <X11/Xlib.h>
#include "../util/logger.hpp"

namespace Engine
{
    namespace Core
    {
        inline Display *current_display = XOpenDisplay(NULL);
        inline Window active_window = None;

        void init_window()
        {
            Logger::assert(current_display != NULL, "Failed to initialise display\n");

            Window root_window = DefaultRootWindow(current_display);

            Logger::assert(root_window != None, "No root window found\n", true, true, [](){XCloseDisplay(current_display);});

            active_window = XCreateSimpleWindow(current_display, root_window, 0, 0, 800, 800, 0, 0, 0xffffffff);

            Logger::assert(active_window != None, "Failed to create window\n", true, true, [](){XCloseDisplay(current_display);});

            XMapWindow(current_display, active_window);

            Atom wm_delete_window = XInternAtom(current_display, "WM_DELETE_WINDOW", False);
            XSetWMProtocols(current_display, active_window, & wm_delete_window, 1);
        }
    }
}

#endif