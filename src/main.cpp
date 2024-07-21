#include <iostream>
#include <cstdlib>

#include "util/logger.hpp"
#include "core/gl.hpp"
#include "core/time.hpp"
#include "core/event.hpp"
#include "core/window.hpp"
#include "core/objects.hpp"
#include "render/cube.hpp"
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

    auto cube = std::make_shared<Render::Cube>();

    Core::drawables.push_back(cube);
    cube->position = Vector3(0, -200, 0);
    cube->size = Vector3(100, 100, 100);

    while (true)
    {
        auto keycodes = Input::check_input();
        cube->position = cube->position + Vector3(0, 20 * Core::delta_time, 0).to_const();
        cube->rotation.x += Core::delta_time * Math::deg_to_rad * 23;
        cube->rotation.y += Core::delta_time * Math::deg_to_rad * 23;
        cube->rotation.z += Core::delta_time * Math::deg_to_rad * 23;
        Core::draw_gl();
    }

    return 0;
}