#ifndef KEA_ENGINE_EVENTSYSTEM_HPP
#define KEA_ENGINE_EVENTSYSTEM_HPP

#include "Event.hpp"

#include <functional>
#include <unordered_map>
#include <vector>

namespace Kea
{
class EventSystem
{
  public:
    using Callback = std::function<void(const Event&)>;

    int Subscribe(EventType type, Callback callback);

    void Unsubscribe(EventType type, int handle);

    void Dispatch(const Event& event);

    static EventSystem& Instance();

  private:
    struct Subscriber
    {
        int handle;
        Callback callback;
    };
    std::unordered_map<EventType, std::vector<Subscriber>> subscribers_;
    int next_handle_ = 1;
};

} // namespace Kea
#endif /* KEA_ENGINE_EVENTSYSTEM_HPP */
