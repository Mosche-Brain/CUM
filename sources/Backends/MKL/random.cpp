#include "cum/random.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

#include <oneapi/mkl/rng.hpp>
#include <oneapi/mkl/rng/device.hpp>
#include <utility>

namespace cum
{
    void random::uniform(const datatype dtype, void* buff, const std::size_t N, const void* min, const void* max, const dim_t seed)
    {
        (void)seed;
        internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
            auto* buff_ptr = static_cast<SyclT*>(buff);
            const SyclT min_val = *static_cast<const SyclT*>(min);
            const SyclT max_val = *static_cast<const SyclT*>(max);

            using ComputeT = internal::math_compute_t<SyclT>;
            ComputeT low = static_cast<ComputeT>(min_val);
            ComputeT high = static_cast<ComputeT>(max_val);

            if (low == high)
            {
                for (std::size_t i = 0; i < N; ++i)
                {
                    buff_ptr[i] = min_val;
                }
                return;
            }
            if (low > high)
            {
                std::swap(low, high);
            }

            oneapi::mkl::rng::device::philox4x32x10<1>& engine = internal::getRNG();
            oneapi::mkl::rng::device::uniform<ComputeT> dist(low, high);

            for (std::size_t i = 0; i < N; ++i)
            {
                buff_ptr[i] = static_cast<SyclT>(oneapi::mkl::rng::device::generate(dist, engine));
            }
        });
    }

    void random::uniform(const datatype dtype, void* buff, const std::size_t N, const cumeric_t min, const cumeric_t max, const dim_t seed)
    {
        const auto min_buf = internal::to_scalar_buffer(dtype, min);
        const auto max_buf = internal::to_scalar_buffer(dtype, max);
        uniform(dtype, buff, N, min_buf.ptr(), max_buf.ptr(), seed);
    }

    void random::uniform(cumeric_t* buff, const std::size_t N, const cumeric_t min, const cumeric_t max, const dim_t seed)
    {
        uniform(default_type, buff, N, &min, &max, seed);
    }

    void random::normal(const datatype dtype, void* buff, const std::size_t N, const void* sigma, const std::size_t seed)
    {
        internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
            auto* buff_ptr = static_cast<SyclT*>(buff);
            const SyclT sigma_val = *static_cast<const SyclT*>(sigma);
            using ComputeT = internal::math_compute_t<SyclT>;
            const ComputeT sigma_c = static_cast<ComputeT>(sigma_val);

            constexpr int VecSize = 4;
            const std::size_t num_items = (N + VecSize - 1) / VecSize;
            internal::getQueue().parallel_for(sycl::range<1>(num_items), [=](sycl::item<1> item) {
                oneapi::mkl::rng::device::philox4x32x10<VecSize>
                    engine(seed, item.get_linear_id() * VecSize);

                oneapi::mkl::rng::device::gaussian<ComputeT> dist(ComputeT(0), sigma_c);
                auto rnd = oneapi::mkl::rng::device::generate(dist, engine);

                const std::size_t base = item.get_linear_id() * VecSize;

                #pragma unroll
                for (int i = 0; i < VecSize && base + i < N; ++i)
                {
                    buff_ptr[base + i] = static_cast<SyclT>(rnd[i]);
                }
            }).wait();
        });
    }

    void random::normal(const datatype dtype, void* buff, const std::size_t N, const cumeric_t sigma, const std::size_t seed)
    {
        const auto sigma_buf = internal::to_scalar_buffer(dtype, sigma);
        normal(dtype, buff, N, sigma_buf.ptr(), seed);
    }

    void random::normal(cumeric_t* buff, const std::size_t N, const cumeric_t sigma, const std::size_t seed)
    {
        normal(default_type, buff, N, &sigma, seed);
    }
}