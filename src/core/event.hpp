#ifndef _EVENT_HPP
#define _EVENT_HPP

#include <forward_list>
#include <functional>

namespace Engine
{
    namespace Core
    {
        typedef unsigned long long unique_id_t;

        class Event
        {
            std::unordered_map<unique_id_t, std::function<void()>> connected_functions;

            static unique_id_t last_id;

            public:

            void trigger();

            unique_id_t bind(std::function<void()> fn);

            void unbind(unique_id_t id);

            std::unordered_map<unique_id_t, std::function<void()>> get_connections();
        };

        static unique_id_t value_event_last_id = 0;

        template <typename A>
        class ValueEvent
        {
            std::unordered_map<unique_id_t, std::function<void(A)>> connected_functions;

            static unique_id_t last_id;

            public:

            void trigger(A value)
            {
                for (const auto& [_, fn] : connected_functions)
                    fn(value);
            }

            unique_id_t bind(std::function<void(A)> fn)
            {
                unique_id_t id = value_event_last_id;
                ++value_event_last_id;

                connected_functions[id] = fn;
                return id;
            }

            void unbind(unique_id_t id)
            {
                bool exists = connected_functions.find(id) != connected_functions.end();

                if (exists)
                    connected_functions.erase(id);
            }

            std::unordered_map<unique_id_t, std::function<void(A)>> get_connections()
            {
                return connected_functions;
            }
        };
    }
}


#endif