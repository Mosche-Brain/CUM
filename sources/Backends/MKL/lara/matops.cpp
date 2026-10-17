#include <oneapi/mkl/blas.hpp>
#include <vector>

#include "cum/Core.hpp"
#include "cum/runtime.hpp"

#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/lara/BLAS/types.hpp"

#include "cum/lara/matops.hpp"

namespace cum::lara
{
	__event__ mmul(datatype dtype, void* C, const void* A, const void* B, const dim_t m, const dim_t n, const dim_t k, __events__ depencies)
	{
		sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
			auto& q = internal::getQueue();
			auto* C_ptr = static_cast<SyclT*>(C);
			auto* A_ptr = static_cast<const SyclT*>(A);
			auto* B_ptr = static_cast<const SyclT*>(B);

			if constexpr (requires {
				oneapi::mkl::blas::row_major::gemm(
					q, oneapi::mkl::transpose::nontrans, oneapi::mkl::transpose::nontrans,
					m, n, k, SyclT(1), A_ptr, k, B_ptr, n, SyclT(0), C_ptr, n);
			}) {
				return oneapi::mkl::blas::row_major::gemm(
					q, oneapi::mkl::transpose::nontrans, oneapi::mkl::transpose::nontrans,
					m, n, k, SyclT(1), A_ptr, k, B_ptr, n, SyclT(0), C_ptr, n);
			}
			else if constexpr (requires(SyclT a, SyclT b) { a = a + a * b; }) {
				return q.parallel_for(
					sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
					[=](sycl::id<2> idx) {
						const auto row = static_cast<dim_t>(idx[0]);
						const auto col = static_cast<dim_t>(idx[1]);
						SyclT acc = SyclT(0);
						for (dim_t p = 0; p < k; ++p) {
							acc = acc + A_ptr[row * k + p] * B_ptr[p * n + col];
						}
						C_ptr[row * n + col] = acc;
					});
			}
			else {
				using ComputeT = internal::math_compute_t<SyclT>;
				return q.parallel_for(
					sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
					[=](sycl::id<2> idx) {
						const auto row = static_cast<dim_t>(idx[0]);
						const auto col = static_cast<dim_t>(idx[1]);
						ComputeT acc = ComputeT(0);
						for (dim_t p = 0; p < k; ++p) {
							acc += static_cast<ComputeT>(A_ptr[row * k + p]) * static_cast<ComputeT>(B_ptr[p * n + col]);
						}
						C_ptr[row * n + col] = static_cast<SyclT>(acc);
					});
			}
		});
		return detail::event_handler::create(std::move(event));
	}

	__event__ mmul(datatype dtype, void* A, const void* B, const dim_t m, const dim_t n, const dim_t k, __events__ depencies)
	{
		return mmul(dtype, A, A, B, m, n, k, std::move(depencies));
	}

	__event__ mmul(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, const dim_t m, const dim_t n, const dim_t k, __events__ depencies)
	{
		return mmul(default_type, C, A, B, m, n, k, std::move(depencies));
	}

	__event__ mmul(cumeric_t* A, const cumeric_t* B, const dim_t m, const dim_t n, const dim_t k)
	{
		return mmul(default_type, A, A, B, m, n, k);
	}

	__event__ mtrans(datatype dtype, void* At, const void* A, const dim_t m, const dim_t n, __events__ depencies)
	{
		sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
			auto& q = internal::getQueue();
			auto* At_ptr = static_cast<SyclT*>(At);
			auto* A_ptr = static_cast<const SyclT*>(A);

			if constexpr (requires {
				oneapi::mkl::blas::row_major::omatcopy(q, oneapi::mkl::transpose::trans, m, n, SyclT(1), A_ptr, n, At_ptr, m);
			}) {
				return oneapi::mkl::blas::row_major::omatcopy(q, oneapi::mkl::transpose::trans, m, n, SyclT(1), A_ptr, n, At_ptr, m);
			}
			else {
				return q.submit([=](sycl::handler& h) {
					h.parallel_for(
						sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
						[=](sycl::id<2> i) {
							At_ptr[i[1] * m + i[0]] = A_ptr[i[0] * n + i[1]];
						});
				});
			}
		});
		return detail::event_handler::create(std::move(event));
	}

	__event__ mtrans(datatype dtype, void* A, const dim_t m, const dim_t n, __events__ depencies)
	{
		return mtrans(dtype, A, A, m, n, std::move(depencies));
	}

	__event__ mtrans(cumeric_t *At, const cumeric_t *A, const dim_t m, const dim_t n, __events__ depencies)
	{
		return mtrans(default_type, At, A, m, n, std::move(depencies));
	}

	__event__ mtrans(cumeric_t* A, const dim_t m, const dim_t n, __events__ depencies)
	{
		return mtrans(default_type, A, A, m, n, std::move(depencies));
	}
}

