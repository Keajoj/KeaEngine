#ifndef KEA_ENGINE_EVENT_HPP
#define KEA_ENGINE_EVENT_HPP

#include "EventType.hpp"
#include <any>

struct Event
{
    EventType type;
    std::any data;
};

#endif /* KEA_ENGINE_EVENT_HPP */
