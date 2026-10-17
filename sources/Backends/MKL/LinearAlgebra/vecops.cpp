//
// Created by jaro on 8/30/26.
//

#include <oneapi/mkl/blas.hpp>

#include "cum/detail/vendor/oneapi/event_handler.hpp"

#include "internal/context.hpp"

#include "cum/LinearAlgebra/vecops.hpp"


namespace cum::LinearAlgebra
{
	__event__ vadd(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		// auto copy = q.copy(v, r, N);
		// oneapi::mkl::blas::row_major::axpy(q, N, 1.0, u, 1, r, 1, {});
		sycl::event event = oneapi::mkl::vm::add(internal::getQueue(),
				n, v, u, r
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vadd(cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::add(internal::getQueue(),
			n, v, u, v
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vsub(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::sub(internal::getQueue(),
			n, v, u, r
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vsub(cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::sub(internal::getQueue(),
			n, v, u, v
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vmul(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::mul(internal::getQueue(),
			n, v, u, r
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vmul(cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::mul(internal::getQueue(),
			n, v, u, v
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vdiv(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::div(internal::getQueue(),
			n, v, u, r
		);	
		return detail::event_handler::create(std::move(event));
	}

	__event__ vdiv(cumeric_t* v, const cumeric_t* u, const dim_t n)
	{
		sycl::event event = oneapi::mkl::vm::div(internal::getQueue(),
			n, v, u, v
		);
		return detail::event_handler::create(std::move(event));
	}

	__event__ vadd(datatype dtype, void* r, const void* v, const void* u, const dim_t n)
	{
		sycl::event event = dispatch_datatype(dtype, [&]<typename T>() -> sycl::event {
			return oneapi::mkl::vm::add(internal::getQueue(),
				n, static_cast<const T*>(v), static_cast<const T*>(u), static_cast<T*>(r)
			);
		});
		return detail::event_handler::create(std::move(event));
	}
}
