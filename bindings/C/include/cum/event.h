#ifndef CUM_C_EVENT_H
#define CUM_C_EVENT_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Functions that accept a trailing `cum_event_t** event` argument are synchronous when it is NULL.
 * Otherwise they return immediately, store a handle in `*event` (NULL on failure) and the
 * caller must release it with cum_event_destroy(). Every buffer used by the operation
 * must stay valid until the event has completed. */

/* Blocks until the operation tracked by `event` has finished. A NULL event is a no-op. */
CUM_C_API cum_status_t cum_event_wait(cum_event_t* event);
/* Releases the handle. Does not wait for the operation; call cum_event_wait() first. */
CUM_C_API cum_status_t cum_event_destroy(cum_event_t* event);
/* Blocks until all work submitted to the device queue has finished. */
CUM_C_API cum_status_t cum_synchronize(void);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_EVENT_H */
