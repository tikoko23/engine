#include <iostream>

#include "util/logger.hpp"
#include "core/event.hpp"
#include "core/window.hpp"
#include "types/vector2.hpp"
#include "modules/input.hpp"
#include "def/keycodes.hpp"

using namespace Engine;

int main()
{
    Core::init_window();
    Input::start_input();

    Vector2 v(23, -23);
    Vector2 v2(14, -14);

    std::cout << (v + v2) << '\n';

    Input::key_pressed_events[Input::KEY_W].bind([](){
        Logger::log("W pressed\n");
    });

    while (1)
    {
        auto keycodes = Input::check_key_input();
    }

    return 0;
}