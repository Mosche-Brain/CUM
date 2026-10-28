"""Runtime control and enumeration types for cumpy."""

from __future__ import annotations

from enum import IntEnum

from ._ffi import check, lib


class Device(IntEnum):
    AUTO = 0
    CPU = 1
    GPU = 2


class DataType(IntEnum):
    FP64 = 0
    FP32 = 1
    FP16 = 2
    BF16 = 3
    FP8 = 4
    S64 = 5
    S32 = 6
    S16 = 7
    S8 = 8
    U64 = 9
    U32 = 10
    U16 = 11
    U8 = 12
    UNDEF = 13


class Layout(IntEnum):
    UNDEF = 0
    ANY = 1
    A = 2
    AB = 3
    BA = 4
    ABC = 5
    ACB = 6
    BAC = 7
    BCA = 8
    CBA = 9
    ABCD = 10
    ABDC = 11
    ACBD = 12
    ACDB = 13
    ADBC = 14
    BACD = 15
    BCDA = 16
    CDBA = 17
    DCAB = 18
    ABCDE = 19
    ABDEC = 20
    ACBDE = 21
    ACDEB = 22
    BACDE = 23
    BCDEA = 24
    CDEBA = 25
    DECAB = 26
    ABCED = 27
    ABCDEF = 28
    ABDFCE = 29
    ACBDEF = 30
    ABDEFC = 31
    DEFCAB = 32
    ABCDFE = 33
    ABCDEFG = 34
    ABCDEGF = 35
    ABCDEFGH = 36
    ABCDEFHG = 37
    ABCDEFGHI = 38
    ABCDEFGIH = 39
    ABCDEFGHIJ = 40
    ABCDEFGHJI = 41
    ABCDEFGHIJK = 42
    ABCDEFGHIKJ = 43
    ABCDEFGHIJKL = 44
    ABCDEFGHIJLK = 45

    # Aliases
    X = 2
    NC = 3
    CN = 4
    NCW = 5
    NWC = 6
    NCHW = 10
    NHWC = 13
    CHWN = 16
    NCDHW = 19
    NDHWC = 22
    OI = 3
    IO = 4
    OIW = 5
    OWI = 6
    WIO = 9
    IWO = 8
    OIHW = 10
    HWIO = 17
    OHWI = 13
    IHWO = 16
    IOHW = 15
    OIDHW = 19
    DHWIO = 25
    ODHWI = 22
    IODHW = 23
    IDHWO = 24
    TNC = 5
    NTC = 7


def init(device: Device | int = Device.AUTO) -> None:
    check(lib.cum_init(int(device)))


def shutdown() -> None:
    check(lib.cum_shutdown())


def synchronize() -> None:
    check(lib.cum_synchronize())


def last_error() -> str:
    raw = lib.cum_last_error()
    return raw.decode("utf-8", errors="replace") if raw else ""
