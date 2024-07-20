#ifndef _TIME_CPP
#define _TIME_CPP

#include <chrono>

namespace Engine
{
    namespace Core
    {
        inline double delta_time = 0;
        inline std::chrono::high_resolution_clock hr_clock = {};

        double get_fps()
        {
            return 1 / delta_time;
        }
    }
}

#endif