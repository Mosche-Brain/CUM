/**
 * @file layout.hpp
 * @brief Memory layout and tensor dimension order tags.
 * @author jaro
 * @details Defines memory stride formatting tags for 1D vectors, 2D matrices (Row/Col major),
 *          and N-dimensional activation, weight, and RNN tensors.
 * @note Derived from oneDNN memory format tags (Apache 2.0 license).
 */

#pragma once

namespace cum
{
    /**
     * @enum layout
     * @brief Memory layout and dimension permutation tags for multi-dimensional tensors.
     */
    enum class layout : unsigned char
    {
        UNDEF, ///< Undefined layout format.
        ANY,   ///< Flexible/unspecified layout (chosen automatically by engine for performance).

        A,     ///< 1D contiguous layout.

        AB,    ///< 2D Row-Major format.
        BA,    ///< 2D Column-Major format.

        ABC,
        ACB,
        BAC,
        BCA,
        CBA,

        ABCD,
        ABDC,
        ACBD,
        ACDB,
        ADBC,
        BACD,
        BCDA,
        CDBA,
        DCAB,

        ABCDE,
        ABDEC,
        ACBDE,
        ACDEB,
        BACDE,
        BCDEA,
        CDEBA,
        DECAB,
        ABCED,

        ABCDEF,
        ABDFCE,
        ACBDEF,
        ABDEFC,
        DEFCAB,
        ABCDFE,

        ABCDEFG,
        ABCDEGF,

        ABCDEFGH,
        ABCDEFHG,

        ABCDEFGHI,
        ABCDEFGIH,

        ABCDEFGHIJ,
        ABCDEFGHJI,

        ABCDEFGHIJK,
        ABCDEFGHIKJ,

        ABCDEFGHIJKL,
        ABCDEFGHIJLK,

        /* 1D Named Aliases */
        X = A,

        /* Activations (Batch N, Channel C, Depth D, Height H, Width W) */
        NC    = AB,
        CN    = BA,
        NCW   = ABC,
        NWC   = ACB,
        NCHW  = ABCD,
        NHWC  = ACDB,
        CHWN  = BCDA,
        NCDHW = ABCDE,
        NDHWC = ACDEB,

        /* Weights (Output O, Input I, Depth D, Height H, Width W) */
        OI    = AB,
        IO    = BA,

        OIW   = ABC,
        OWI   = ACB,
        WIO   = CBA,
        IWO   = BCA,

        OIHW  = ABCD,
        HWIO  = CDBA,
        OHWI  = ACDB,
        IHWO  = BCDA,
        IOHW  = BACD,

        OIDHW = ABCDE,
        DHWIO = CDEBA,
        ODHWI = ACDEB,
        IODHW = BACDE,
        IDHWO = BCDEA,

        /* Grouped weights (Group G, Output O, Input I, Depth D, Height H, Width W) */
        GOIW   = ABCD,
        GOWI   = ABDC,
        WIGO   = DCAB,

        GOHWI  = ABDEC,
        GOIHW  = ABCDE,
        HWIGO  = DECAB,
        GIOHW  = ACBDE,

        GOIDHW = ABCDEF,
        GIODHW = ACBDEF,
        GODHWI = ABDEFC,
        DHWIGO = DEFCAB,

        /* Recurrent Neural Network (Time T, Batch N, Channel C, Layer L, Direction D, etc.) */
        TN    = AB,
        NT    = BA,
        TNC   = ABC,
        NTC   = BAC,

        LDNC  = ABCD,
        LDIGO = ABCDE,
        LDGOI = ABDEC,
        LDIO  = ABCD,
        LDOI  = ABDC,
        LDGO  = ABCD,
    };

} // namespace cum
