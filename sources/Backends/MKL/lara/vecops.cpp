//
// Created by jaro on 8/30/26.
//

#include <oneapi/mkl/blas.hpp>

#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

#include "../../../../include/cum/detail/vendor/oneapi/context.hpp"

#include "cum/lara/vecops.hpp"


namespace cum::lara
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
		return internal::dispatch_vm_binary(dtype, r, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::add(q, len, a, b, res)) {
				return oneapi::mkl::vm::add(q, len, a, b, res);
			},
			std::plus<>{}
		);
	}

	__event__ vadd(datatype dtype, void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, v, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::add(q, len, a, b, res)) {
				return oneapi::mkl::vm::add(q, len, a, b, res);
			},
			std::plus<>{}
		);
	}

	__event__ vsub(datatype dtype, void* r, const void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, r, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::sub(q, len, a, b, res)) {
				return oneapi::mkl::vm::sub(q, len, a, b, res);
			},
			std::minus<>{}
		);
	}

	__event__ vsub(datatype dtype, void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, v, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::sub(q, len, a, b, res)) {
				return oneapi::mkl::vm::sub(q, len, a, b, res);
			},
			std::minus<>{}
		);
	}

	__event__ vmul(datatype dtype, void* r, const void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, r, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::mul(q, len, a, b, res)) {
				return oneapi::mkl::vm::mul(q, len, a, b, res);
			},
			std::multiplies<>{}
		);
	}

	__event__ vmul(datatype dtype, void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, v, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::mul(q, len, a, b, res)) {
				return oneapi::mkl::vm::mul(q, len, a, b, res);
			},
			std::multiplies<>{}
		);
	}

	__event__ vdiv(datatype dtype, void* r, const void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, r, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::div(q, len, a, b, res)) {
				return oneapi::mkl::vm::div(q, len, a, b, res);
			},
			std::divides<>{}
		);
	}

	__event__ vdiv(datatype dtype, void* v, const void* u, const dim_t n)
	{
		return internal::dispatch_vm_binary(dtype, v, v, u, n,
			[](auto& q, auto len, auto* a, auto* b, auto* res) -> decltype(oneapi::mkl::vm::div(q, len, a, b, res)) {
				return oneapi::mkl::vm::div(q, len, a, b, res);
			},
			std::divides<>{}
		);
	}

	
}
