"""Asynchronous execution event wrapper over cum_event_t."""

from __future__ import annotations

import weakref

from ._ffi import check, cum_event_p, lib


class Event:
    """Handle to an asynchronous device/primitive operation."""

    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(self, *, _ptr: cum_event_p) -> None:
        if _ptr is None or not bool(_ptr):
            raise ValueError("Event requires a valid non-null cum_event_p handle")
        self._ptr = _ptr
        self._finalizer = weakref.finalize(self, lib.cum_event_destroy, _ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_event_p) -> Event:
        return cls(_ptr=ptr)

    def wait(self) -> Event:
        """Blocks until the asynchronous operation tracked by this event completes."""
        check(lib.cum_event_wait(self._ptr))
        return self

    def __repr__(self) -> str:
        addr = int(getattr(self._ptr, "value", 0) or 0)
        return f"Event(0x{addr:x})" if addr else "Event()"
