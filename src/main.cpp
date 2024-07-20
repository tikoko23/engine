#include <iostream>
#include <cstdlib>

#include "util/logger.hpp"
#include "core/gl.hpp"
#include "core/time.hpp"
#include "core/event.hpp"
#include "core/window.hpp"
#include "types/vector2.hpp"
#include "modules/input.hpp"
#include "def/keycodes.hpp"

using namespace Engine;

int main()
{
    Core::init_window(0, 0, 800, 800, 0);
    Core::init_opengl();
    Input::start_input();

    Input::key_pressed_events[Input::KEY_W].bind([](){
        Logger::log("W pressed\n");
    });

    std::atexit([](){
        Core::end_opengl();
        Core::end_window();
    });

    while (true)
    {
        auto keycodes = Input::check_input();
        Core::draw_gl();
        Logger::log(std::to_string(Core::get_fps()) + '\n');
    }

    return 0;
}