#include "cum/cum.h"
#include "cum/memory.hpp"
#include "cum/runtime.hpp"
#include "cum/detail/error.hpp"
#include "cum/detail/opaques_impl.hpp"

using cum_c::guard;
using cum_c::invalid_argument;

extern "C"
{
    cum_status_t cum_event_wait(cum_event_t* event)
    {
        if(event == nullptr)
            return CUM_STATUS_SUCCESS;
        return guard([&] { event->event.wait(); });
    }

    cum_status_t cum_event_destroy(cum_event_t* event)
    {
        delete event;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_synchronize(void)
    {
        return guard([] { cum::runtime::sync(); });
    }

    cum_status_t cum_memory_allocate(dim_t count, cumeric_t** data)
    {
        if(data == nullptr || count <= 0)
            return invalid_argument("invalid output pointer or element count");
        return guard([&] { *data = cum::memory::allocate(count); });
    }

    cum_status_t cum_memory_free(void* data)
    {
        return guard([&] { if(data != nullptr) cum::memory::free(data); });
    }
}
