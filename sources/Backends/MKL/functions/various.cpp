//
// Created by jaro on 7/19/26.
//

#include <sycl/sycl.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/functions/various.hpp"

#include <oneapi/dpl/algorithm>
#include <oneapi/dpl/execution>

#include "cum/memory.hpp"

namespace cum::functions::various
{
    void fill(datatype dtype, void* v, const cumeric_t val, const std::size_t N)
    {
        if (N == 0) return;

        internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
            auto& q = internal::getQueue();
            auto* v_ptr = static_cast<SyclT*>(v);
            using ComputeT = internal::math_compute_t<SyclT>;
            const SyclT typed_val = static_cast<SyclT>(static_cast<ComputeT>(val));
            q.parallel_for(sycl::range<1>(N), [=](sycl::id<1> idx) {
                v_ptr[idx] = typed_val;
            }).wait();
        });
    }

    void fill(cumeric_t* v, const cumeric_t val, const std::size_t N)
    {
        if (N == 0) return;

        sycl::ext::oneapi::experimental::fill(internal::getQueue(), v, val, N);
    }

    cumeric_t clamp(cumeric_t a, cumeric_t min, cumeric_t max)
    {
        return sycl::clamp(a, min, max);
    }

    cumeric_t min(const cumeric_t a, const cumeric_t b) { return sycl::min(a, b); }

    cumeric_t max(const cumeric_t a, const cumeric_t b) { return sycl::max(a, b); }

    cumeric_t abs(cumeric_t x)
    {
        return sycl::fabs(x);
    }

    void clip(datatype dtype, void* r, const void* v, const cumeric_t min_val, const cumeric_t max_val, const std::size_t N)
    {
        internal::dispatch_unary_math(dtype, r, v, N, [=](auto x) {
            using T = decltype(x);
            const T lo = static_cast<T>(min_val);
            const T hi = static_cast<T>(max_val);
            return x > lo && x < hi ? x : (x < lo ? lo : hi);
        }).wait();
    }

    void clipInPlace(datatype dtype, void* v, const cumeric_t min_val, const cumeric_t max_val, const std::size_t N)
    {
        clip(dtype, v, v, min_val, max_val, N);
    }

    // temporary naive implementation
    void clip(cumeric_t* r, const cumeric_t* v, const cumeric_t min, const cumeric_t max, const std::size_t N)
    {
        for(size_t i = 0 ; i < N ; i++) { r[i] = v[i] > min && v[i] < max ? v[i] : v[i] < min ? min : max; };
    }

    // temporary naive implementation
    void clipInPlace(cumeric_t* v, const cumeric_t min, const cumeric_t max, const std::size_t N)
    {
        for(size_t i = 0 ; i < N ; i++) { v[i] = v[i] > min && v[i] < max ? v[i] : v[i] < min ? min : max; };
    }

    bool equal(datatype dtype, const void* v, const void* u, const std::size_t N)
    {
        return internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> bool {
            auto* v_ptr = static_cast<const SyclT*>(v);
            auto* u_ptr = static_cast<const SyclT*>(u);
            if constexpr (requires(SyclT a, SyclT b) { { a == b } -> std::convertible_to<bool>; }) {
                for (std::size_t i = 0; i < N; ++i) {
                    if (!(v_ptr[i] == u_ptr[i])) return false;
                }
                return true;
            } else {
                using ComputeT = internal::math_compute_t<SyclT>;
                for (std::size_t i = 0; i < N; ++i) {
                    if (static_cast<ComputeT>(v_ptr[i]) != static_cast<ComputeT>(u_ptr[i])) return false;
                }
                return true;
            }
        });
    }

    bool equal(const cumeric_t* v, const cumeric_t* u, const std::size_t N)
    {
        auto policy = oneapi::dpl::execution::make_device_policy(internal::getQueue());
        return std::equal(policy, v, v + N, u);
    }

    void linespace(datatype dtype, void* v, const cumeric_t start, const cumeric_t end, const std::size_t N)
    {
        if (N == 0) return;

        internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
            auto& q = internal::getQueue();
            auto* v_ptr = static_cast<SyclT*>(v);
            using ComputeT = internal::math_compute_t<SyclT>;
            const ComputeT s = static_cast<ComputeT>(start);
            const ComputeT e = static_cast<ComputeT>(end);

            q.parallel_for(sycl::range<1>(N), [=](sycl::id<1> idx) {
                const std::size_t i = idx[0];
                if (N == 1) {
                    v_ptr[i] = static_cast<SyclT>(s);
                } else {
                    v_ptr[i] = static_cast<SyclT>(s + static_cast<ComputeT>(i) * (e - s) / static_cast<ComputeT>(N - 1));
                }
            }).wait();
        });
    }

    void linespace(cumeric_t* v, const cumeric_t start, const cumeric_t end, const std::size_t N)
    {
        linespace(default_type, v, start, end, N);
    }
}

