#include <px4_platform_common/events.h>
#include <uORB/Publication.hpp>
#include <uORB/topics/event.h>

namespace events
{

void send(EventType &event)
{
    static uORB::Publication<event_s> event_pub{ORB_ID(event)};
    event_s e{};
    e.timestamp = hrt_absolute_time();
    e.id = event.id;
    e.log_levels = event.log_levels;
    memcpy(e.arguments, event.arguments, sizeof(e.arguments));
    event_pub.publish(e);
}

} // namespace events
