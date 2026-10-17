// Created by Jaro 8/30/26
#pragma once
#include "cum/Core.hpp"
#include "BLAS/level3.hpp"

namespace cum::lara
{
	__event__ mmul(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});
	__event__ mmul(cumeric_t* A, const cumeric_t* B, dim_t m, dim_t n, dim_t k);
	__event__ mmul(datatype dtype, void* C, const void* A, const void* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});
	__event__ mmul(datatype dtype, void* A, const void* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});

	__event__ mtrans(cumeric_t* At, const cumeric_t* A, dim_t m, dim_t n, __events__ depencies={});
	__event__ mtrans(cumeric_t* A, dim_t m, dim_t n, __events__ depencies={});
	__event__ mtrans(datatype dtype, void* At, const void* A, dim_t m, dim_t n, __events__ depencies={});
	__event__ mtrans(datatype dtype, void* A, dim_t m, dim_t n, __events__ depencies={});
}

