#include <type_traits>

#include "cum/cum.h"
#include "cum/cum.hpp"
#include "cum/detail/error.hpp"
#include "cum/detail/convert.hpp"

static_assert(std::is_same_v<cumeric_t, cum::cumeric_t>,
    "the C binding supports only the FP32 build of CUM (CUM_USE_FP32)");
static_assert(std::is_same_v<dim_t, cum::dim_t>, "dim_t mismatch between C and C++ APIs");

static_assert(static_cast<int>(cum::DEVICE::AUTO) == CUM_DEVICE_AUTO, "cum_device_t mismatch");
static_assert(static_cast<int>(cum::DEVICE::CPU) == CUM_DEVICE_CPU, "cum_device_t mismatch");
static_assert(static_cast<int>(cum::DEVICE::GPU) == CUM_DEVICE_GPU, "cum_device_t mismatch");

static_assert(static_cast<int>(cum::datatype::FP64) == CUM_DATATYPE_FP64, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::FP32) == CUM_DATATYPE_FP32, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::FP16) == CUM_DATATYPE_FP16, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::BF16) == CUM_DATATYPE_BF16, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::FP8) == CUM_DATATYPE_FP8, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::S64) == CUM_DATATYPE_S64, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::S32) == CUM_DATATYPE_S32, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::S16) == CUM_DATATYPE_S16, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::S8) == CUM_DATATYPE_S8, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::U64) == CUM_DATATYPE_U64, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::U32) == CUM_DATATYPE_U32, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::U16) == CUM_DATATYPE_U16, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::U8) == CUM_DATATYPE_U8, "cum_datatype_t mismatch");
static_assert(static_cast<int>(cum::datatype::UNDEF) == CUM_DATATYPE_UNDEF, "cum_datatype_t mismatch");

static_assert(static_cast<int>(cum::layout::UNDEF) == CUM_LAYOUT_UNDEF, "cum_layout_t::UNDEF mismatch");
static_assert(static_cast<int>(cum::layout::ANY) == CUM_LAYOUT_ANY, "cum_layout_t::ANY mismatch");
static_assert(static_cast<int>(cum::layout::A) == CUM_LAYOUT_A, "cum_layout_t::A mismatch");
static_assert(static_cast<int>(cum::layout::AB) == CUM_LAYOUT_AB, "cum_layout_t::AB mismatch");
static_assert(static_cast<int>(cum::layout::BA) == CUM_LAYOUT_BA, "cum_layout_t::BA mismatch");
static_assert(static_cast<int>(cum::layout::ABC) == CUM_LAYOUT_ABC, "cum_layout_t::ABC mismatch");
static_assert(static_cast<int>(cum::layout::ACB) == CUM_LAYOUT_ACB, "cum_layout_t::ACB mismatch");
static_assert(static_cast<int>(cum::layout::BAC) == CUM_LAYOUT_BAC, "cum_layout_t::BAC mismatch");
static_assert(static_cast<int>(cum::layout::BCA) == CUM_LAYOUT_BCA, "cum_layout_t::BCA mismatch");
static_assert(static_cast<int>(cum::layout::CBA) == CUM_LAYOUT_CBA, "cum_layout_t::CBA mismatch");
static_assert(static_cast<int>(cum::layout::ABCD) == CUM_LAYOUT_ABCD, "cum_layout_t::ABCD mismatch");
static_assert(static_cast<int>(cum::layout::ABDC) == CUM_LAYOUT_ABDC, "cum_layout_t::ABDC mismatch");
static_assert(static_cast<int>(cum::layout::ACBD) == CUM_LAYOUT_ACBD, "cum_layout_t::ACBD mismatch");
static_assert(static_cast<int>(cum::layout::ACDB) == CUM_LAYOUT_ACDB, "cum_layout_t::ACDB mismatch");
static_assert(static_cast<int>(cum::layout::ADBC) == CUM_LAYOUT_ADBC, "cum_layout_t::ADBC mismatch");
static_assert(static_cast<int>(cum::layout::BACD) == CUM_LAYOUT_BACD, "cum_layout_t::BACD mismatch");
static_assert(static_cast<int>(cum::layout::BCDA) == CUM_LAYOUT_BCDA, "cum_layout_t::BCDA mismatch");
static_assert(static_cast<int>(cum::layout::CDBA) == CUM_LAYOUT_CDBA, "cum_layout_t::CDBA mismatch");
static_assert(static_cast<int>(cum::layout::DCAB) == CUM_LAYOUT_DCAB, "cum_layout_t::DCAB mismatch");
static_assert(static_cast<int>(cum::layout::ABCDE) == CUM_LAYOUT_ABCDE, "cum_layout_t::ABCDE mismatch");
static_assert(static_cast<int>(cum::layout::ABDEC) == CUM_LAYOUT_ABDEC, "cum_layout_t::ABDEC mismatch");
static_assert(static_cast<int>(cum::layout::ACBDE) == CUM_LAYOUT_ACBDE, "cum_layout_t::ACBDE mismatch");
static_assert(static_cast<int>(cum::layout::ACDEB) == CUM_LAYOUT_ACDEB, "cum_layout_t::ACDEB mismatch");
static_assert(static_cast<int>(cum::layout::BACDE) == CUM_LAYOUT_BACDE, "cum_layout_t::BACDE mismatch");
static_assert(static_cast<int>(cum::layout::BCDEA) == CUM_LAYOUT_BCDEA, "cum_layout_t::BCDEA mismatch");
static_assert(static_cast<int>(cum::layout::CDEBA) == CUM_LAYOUT_CDEBA, "cum_layout_t::CDEBA mismatch");
static_assert(static_cast<int>(cum::layout::DECAB) == CUM_LAYOUT_DECAB, "cum_layout_t::DECAB mismatch");
static_assert(static_cast<int>(cum::layout::ABCED) == CUM_LAYOUT_ABCED, "cum_layout_t::ABCED mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEF) == CUM_LAYOUT_ABCDEF, "cum_layout_t::ABCDEF mismatch");
static_assert(static_cast<int>(cum::layout::ABDFCE) == CUM_LAYOUT_ABDFCE, "cum_layout_t::ABDFCE mismatch");
static_assert(static_cast<int>(cum::layout::ACBDEF) == CUM_LAYOUT_ACBDEF, "cum_layout_t::ACBDEF mismatch");
static_assert(static_cast<int>(cum::layout::ABDEFC) == CUM_LAYOUT_ABDEFC, "cum_layout_t::ABDEFC mismatch");
static_assert(static_cast<int>(cum::layout::DEFCAB) == CUM_LAYOUT_DEFCAB, "cum_layout_t::DEFCAB mismatch");
static_assert(static_cast<int>(cum::layout::ABCDFE) == CUM_LAYOUT_ABCDFE, "cum_layout_t::ABCDFE mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFG) == CUM_LAYOUT_ABCDEFG, "cum_layout_t::ABCDEFG mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEGF) == CUM_LAYOUT_ABCDEGF, "cum_layout_t::ABCDEGF mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGH) == CUM_LAYOUT_ABCDEFGH, "cum_layout_t::ABCDEFGH mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFHG) == CUM_LAYOUT_ABCDEFHG, "cum_layout_t::ABCDEFHG mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHI) == CUM_LAYOUT_ABCDEFGHI, "cum_layout_t::ABCDEFGHI mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGIH) == CUM_LAYOUT_ABCDEFGIH, "cum_layout_t::ABCDEFGIH mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHIJ) == CUM_LAYOUT_ABCDEFGHIJ, "cum_layout_t::ABCDEFGHIJ mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHJI) == CUM_LAYOUT_ABCDEFGHJI, "cum_layout_t::ABCDEFGHJI mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHIJK) == CUM_LAYOUT_ABCDEFGHIJK, "cum_layout_t::ABCDEFGHIJK mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHIKJ) == CUM_LAYOUT_ABCDEFGHIKJ, "cum_layout_t::ABCDEFGHIKJ mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHIJKL) == CUM_LAYOUT_ABCDEFGHIJKL, "cum_layout_t::ABCDEFGHIJKL mismatch");
static_assert(static_cast<int>(cum::layout::ABCDEFGHIJLK) == CUM_LAYOUT_ABCDEFGHIJLK, "cum_layout_t::ABCDEFGHIJLK mismatch");
static_assert(static_cast<int>(cum::layout::X) == CUM_LAYOUT_X, "cum_layout_t::X mismatch");
static_assert(static_cast<int>(cum::layout::NC) == CUM_LAYOUT_NC, "cum_layout_t::NC mismatch");
static_assert(static_cast<int>(cum::layout::CN) == CUM_LAYOUT_CN, "cum_layout_t::CN mismatch");
static_assert(static_cast<int>(cum::layout::NCW) == CUM_LAYOUT_NCW, "cum_layout_t::NCW mismatch");
static_assert(static_cast<int>(cum::layout::NWC) == CUM_LAYOUT_NWC, "cum_layout_t::NWC mismatch");
static_assert(static_cast<int>(cum::layout::NCHW) == CUM_LAYOUT_NCHW, "cum_layout_t::NCHW mismatch");
static_assert(static_cast<int>(cum::layout::NHWC) == CUM_LAYOUT_NHWC, "cum_layout_t::NHWC mismatch");
static_assert(static_cast<int>(cum::layout::CHWN) == CUM_LAYOUT_CHWN, "cum_layout_t::CHWN mismatch");
static_assert(static_cast<int>(cum::layout::NCDHW) == CUM_LAYOUT_NCDHW, "cum_layout_t::NCDHW mismatch");
static_assert(static_cast<int>(cum::layout::NDHWC) == CUM_LAYOUT_NDHWC, "cum_layout_t::NDHWC mismatch");
static_assert(static_cast<int>(cum::layout::OI) == CUM_LAYOUT_OI, "cum_layout_t::OI mismatch");
static_assert(static_cast<int>(cum::layout::IO) == CUM_LAYOUT_IO, "cum_layout_t::IO mismatch");
static_assert(static_cast<int>(cum::layout::OIW) == CUM_LAYOUT_OIW, "cum_layout_t::OIW mismatch");
static_assert(static_cast<int>(cum::layout::OWI) == CUM_LAYOUT_OWI, "cum_layout_t::OWI mismatch");
static_assert(static_cast<int>(cum::layout::WIO) == CUM_LAYOUT_WIO, "cum_layout_t::WIO mismatch");
static_assert(static_cast<int>(cum::layout::IWO) == CUM_LAYOUT_IWO, "cum_layout_t::IWO mismatch");
static_assert(static_cast<int>(cum::layout::OIHW) == CUM_LAYOUT_OIHW, "cum_layout_t::OIHW mismatch");
static_assert(static_cast<int>(cum::layout::HWIO) == CUM_LAYOUT_HWIO, "cum_layout_t::HWIO mismatch");
static_assert(static_cast<int>(cum::layout::OHWI) == CUM_LAYOUT_OHWI, "cum_layout_t::OHWI mismatch");
static_assert(static_cast<int>(cum::layout::IHWO) == CUM_LAYOUT_IHWO, "cum_layout_t::IHWO mismatch");
static_assert(static_cast<int>(cum::layout::IOHW) == CUM_LAYOUT_IOHW, "cum_layout_t::IOHW mismatch");
static_assert(static_cast<int>(cum::layout::OIDHW) == CUM_LAYOUT_OIDHW, "cum_layout_t::OIDHW mismatch");
static_assert(static_cast<int>(cum::layout::DHWIO) == CUM_LAYOUT_DHWIO, "cum_layout_t::DHWIO mismatch");
static_assert(static_cast<int>(cum::layout::ODHWI) == CUM_LAYOUT_ODHWI, "cum_layout_t::ODHWI mismatch");
static_assert(static_cast<int>(cum::layout::IODHW) == CUM_LAYOUT_IODHW, "cum_layout_t::IODHW mismatch");
static_assert(static_cast<int>(cum::layout::IDHWO) == CUM_LAYOUT_IDHWO, "cum_layout_t::IDHWO mismatch");
static_assert(static_cast<int>(cum::layout::GOIW) == CUM_LAYOUT_GOIW, "cum_layout_t::GOIW mismatch");
static_assert(static_cast<int>(cum::layout::GOWI) == CUM_LAYOUT_GOWI, "cum_layout_t::GOWI mismatch");
static_assert(static_cast<int>(cum::layout::WIGO) == CUM_LAYOUT_WIGO, "cum_layout_t::WIGO mismatch");
static_assert(static_cast<int>(cum::layout::GOHWI) == CUM_LAYOUT_GOHWI, "cum_layout_t::GOHWI mismatch");
static_assert(static_cast<int>(cum::layout::GOIHW) == CUM_LAYOUT_GOIHW, "cum_layout_t::GOIHW mismatch");
static_assert(static_cast<int>(cum::layout::HWIGO) == CUM_LAYOUT_HWIGO, "cum_layout_t::HWIGO mismatch");
static_assert(static_cast<int>(cum::layout::GIOHW) == CUM_LAYOUT_GIOHW, "cum_layout_t::GIOHW mismatch");
static_assert(static_cast<int>(cum::layout::GOIDHW) == CUM_LAYOUT_GOIDHW, "cum_layout_t::GOIDHW mismatch");
static_assert(static_cast<int>(cum::layout::GIODHW) == CUM_LAYOUT_GIODHW, "cum_layout_t::GIODHW mismatch");
static_assert(static_cast<int>(cum::layout::GODHWI) == CUM_LAYOUT_GODHWI, "cum_layout_t::GODHWI mismatch");
static_assert(static_cast<int>(cum::layout::DHWIGO) == CUM_LAYOUT_DHWIGO, "cum_layout_t::DHWIGO mismatch");
static_assert(static_cast<int>(cum::layout::TN) == CUM_LAYOUT_TN, "cum_layout_t::TN mismatch");
static_assert(static_cast<int>(cum::layout::NT) == CUM_LAYOUT_NT, "cum_layout_t::NT mismatch");
static_assert(static_cast<int>(cum::layout::TNC) == CUM_LAYOUT_TNC, "cum_layout_t::TNC mismatch");
static_assert(static_cast<int>(cum::layout::NTC) == CUM_LAYOUT_NTC, "cum_layout_t::NTC mismatch");
static_assert(static_cast<int>(cum::layout::LDNC) == CUM_LAYOUT_LDNC, "cum_layout_t::LDNC mismatch");
static_assert(static_cast<int>(cum::layout::LDIGO) == CUM_LAYOUT_LDIGO, "cum_layout_t::LDIGO mismatch");
static_assert(static_cast<int>(cum::layout::LDGOI) == CUM_LAYOUT_LDGOI, "cum_layout_t::LDGOI mismatch");
static_assert(static_cast<int>(cum::layout::LDIO) == CUM_LAYOUT_LDIO, "cum_layout_t::LDIO mismatch");
static_assert(static_cast<int>(cum::layout::LDOI) == CUM_LAYOUT_LDOI, "cum_layout_t::LDOI mismatch");
static_assert(static_cast<int>(cum::layout::LDGO) == CUM_LAYOUT_LDGO, "cum_layout_t::LDGO mismatch");

extern "C"
{
    cum_status_t cum_init(cum_device_t device)
    {
        return cum_c::guard([&] { cum::cum(static_cast<cum::DEVICE>(device)); });
    }

    cum_status_t cum_shutdown(void)
    {
        return cum_c::guard([] { cum::decum(); });
    }

    const char* cum_last_error(void)
    {
        return cum_c::last_error.c_str();
    }
}
