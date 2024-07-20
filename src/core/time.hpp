#ifndef _TIME_HPP
#define _TIME_HPP

#include <chrono>

namespace Engine
{
    namespace Core
    {
        inline double delta_time;
        inline std::chrono::high_resolution_clock hr_clock;

        double get_fps();
    }
}

#endif