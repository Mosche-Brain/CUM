#ifndef CUM_C_SUBMIT_HPP
#define CUM_C_SUBMIT_HPP

#include "cum/detail/error.hpp"
#include "cum/detail/opaques_impl.hpp"

namespace cum_c
{
    /* Runs `operation` (returning cum::__event__). Without an `event` output the call blocks
     * until completion, otherwise the event is handed over to the caller. */
    template<typename Operation>
    cum_status_t submit(cum_event_t** event, Operation&& operation)
    {
        if(event != nullptr)
            *event = nullptr;

        return guard([&] {
            cum::__event__ pending = operation();
            if(event == nullptr)
                pending.wait();
            else
                *event = new cum_event_t { std::move(pending) };
        });
    }
}

#endif /* CUM_C_SUBMIT_HPP */
