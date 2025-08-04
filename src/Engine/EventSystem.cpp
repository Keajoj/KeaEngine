#include "EventSystem.hpp"
namespace Kea
{

int EventSystem::Subscribe(EventType type, Callback callback)
{
    int handle = next_handle_++;
    subscribers_[type].push_back({handle, std::move(callback)});
    return handle;
}

void EventSystem::Unsubscribe(EventType type, int handle)
{
    auto& vec = subscribers_[type];
    vec.erase(std::remove_if(vec.begin(), vec.end(), [handle](const Subscriber& s) { return s.handle == handle; }),
              vec.end());
}

void EventSystem::Dispatch(const Event& event)
{
    auto it = subscribers_.find(event.type);
    if (it != subscribers_.end())
    {
        for (const auto& sub : it->second)
        {
            sub.callback(event);
        }
    }
}

EventSystem& EventSystem::Instance()
{
    static EventSystem instance;
    return instance;
}

} // namespace Kea