#ifndef _INPUT_CPP
#define _INPUT_CPP

#include <vector>
#include <unordered_map>
#include <utility>
#include <cstdint>
#include <X11/Xlib.h>

#include "../util/logger.hpp"
#include "../core/window.hpp"
#include "../core/event.hpp"
#include "../def/keycodes.hpp"

namespace Engine
{
    namespace Input
    {
        void start_input()
        {
            Logger::assert(Core::active_window != None, "A window should be initialised first\n");
            XSelectInput(Core::current_display, Core::active_window, KeyPressMask | KeyReleaseMask);
        }

        inline Core::ValueEvent<std::vector<std::pair<uint32_t, int>>> key_updated = {};

        inline std::unordered_map<KeyboardKeys, Core::Event> key_pressed_events = {};
        inline std::unordered_map<KeyboardKeys, Core::Event> key_released_events = {};
        inline std::unordered_map<KeyboardKeys, bool> key_down = {};

        std::vector<std::pair<uint32_t, int>> check_key_input()
        {
            std::vector<std::pair<uint32_t, int>> keycodes = {};

            while (XPending(Core::current_display))
            {
                XEvent event;
                XNextEvent(Core::current_display, &event);

                keycodes.push_back(std::make_pair(event.xkey.keycode, event.type));

                if (event.type == KeyPress)
                {
                    key_pressed_events[static_cast<KeyboardKeys>(event.xkey.keycode)].trigger();
                    key_down[static_cast<KeyboardKeys>(event.xkey.keycode)] = true;
                }
                else if (event.type == KeyRelease)
                {
                    key_released_events[static_cast<KeyboardKeys>(event.xkey.keycode)].trigger();
                    key_down[static_cast<KeyboardKeys>(event.xkey.keycode)] = false;
                }
            }

            if (keycodes.size() > 0)
                key_updated.trigger(keycodes);

            return keycodes;
        }
    }
}


#endif