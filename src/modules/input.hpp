#ifndef _INPUT_HPP
#define _INPUT_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <cstdint>

#include "../core/event.hpp"
#include "../def/keycodes.hpp"

namespace Engine
{
    namespace Input
    {
        void start_input();

        inline Core::ValueEvent<std::vector<std::pair<uint32_t, int>>> key_updated;

        inline std::unordered_map<KeyboardKeys, Core::Event> key_pressed_events;
        inline std::unordered_map<KeyboardKeys, Core::Event> key_released_events;
        inline std::unordered_map<KeyboardKeys, bool> key_down;

        std::vector<std::pair<uint32_t, int>> check_key_input();
    }
}

#endif