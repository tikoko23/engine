#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <X11/Xlib.h>

namespace Engine
{
    namespace Core
    {
        inline Display *current_display;
        inline Window active_window;

        void init_window(
            int pos_x = 0, int pos_y = 0,
            unsigned int size_x = 800, unsigned int size_y = 800,
            unsigned int border_width = 0, unsigned long border = 0,
            unsigned int bg_color = 0xffffffff
        );
    }
}

#endif