#ifndef _EVENT_CPP
#define _EVENT_CPP

#include <forward_list>
#include <functional>

namespace Engine
{
    namespace Core
    {
        class Event
        {
            std::forward_list<std::function<void>> connected_functions;
        }
    }
}


#endif