#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <X11/Xlib.h>

namespace Engine
{
    namespace Core
    {
        inline Display *current_display;
        inline Window active_window;

        void init_window();
    }
}

#endif