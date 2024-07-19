#ifndef _EVENT_CPP
#define _EVENT_CPP

#include <forward_list>
#include <functional>
#include "event.hpp"

namespace Engine
{
    namespace Core
    {
        typedef unsigned long long unique_id_t;

        unique_id_t Event::last_id = 0;

        void Event::trigger()
        {
            for (const auto& [_, fn] : connected_functions)
                fn();
        }

        unique_id_t Event::bind(std::function<void()> fn)
        {
            unique_id_t id = last_id;
            ++last_id;

            connected_functions[id] = fn;
            return id;
        }

        void Event::unbind(unique_id_t id)
        {
            bool exists = connected_functions.find(id) != connected_functions.end();

            if (exists)
                connected_functions.erase(id);
        }

        std::unordered_map<unique_id_t, std::function<void()>> Event::get_connections()
        {
            return connected_functions;
        }
    }
}


#endif