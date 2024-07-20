#ifndef _LOGGER_CPP
#define _LOGGER_CPP

#include <iostream>
#include <functional>
#include <string>

namespace Engine
{ 
    namespace Logger
    {
        void log(std::string message, bool severity_stamp = true)
        {
            std::string severity = "";

            if (severity_stamp)
                severity = "INFO: ";

            std::cout << "\x1b[38;5;75m" << severity << message << "\x1b[0m";
        }

        void log_gl(std::string message, bool severity_stamp = true)
        {
            std::string severity = "";

            if (severity_stamp)
                severity = "GL: ";

            std::cout << "\x1b[38;5;157m" << severity << message << "\x1b[0m";
        }

        void warn(std::string message, bool severity_stamp = true)
        {
            std::string severity = "";

            if (severity_stamp)
                severity = "WARN: ";

            std::cout << "\x1b[38;5;220m" << severity << message << "\x1b[0m";
        }

        void error(std::string message, bool severity_stamp = true)
        {
            std::string severity = "";

            if (severity_stamp)
                severity = "ERROR: ";

            std::cerr << "\x1b[38;5;196m" << severity << message << "\x1b[0m";
        }

        bool assert(bool condition, std::string error_message, bool throws = true, bool severity_stamp = true, std::function<void()> cleanup = [](){})
        {
            if (!condition)
            {
                std::string severity = "";

                if (severity_stamp)
                    severity = "ASSERT: ";

                std::cerr << "\x1b[38;5;208m" << severity << error_message << "\x1b[0m";
                cleanup();
                if (throws)
                    throw std::runtime_error("Failed assertion: " + error_message);
            }

            return condition;
        }
    }
}

#endif