#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include <string>
#include <functional>

namespace Engine
{ 
    namespace Logger
    {
        void log(std::string message, bool severity_stamp = true);

        void warn(std::string message, bool severity_stamp = true);

        void error(std::string message, bool severity_stamp = true);

        bool assert(bool condition, std::string error_message, bool throws = true, bool severity_stamp = true, std::function<void()> cleanup = [](){});
    }
}

#endif