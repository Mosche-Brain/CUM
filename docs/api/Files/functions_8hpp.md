---
title: include/cum/functions.hpp
summary: Master include header and functor definitions for neural activation and mathematical functions. 

---

# include/cum/functions.hpp

Master include header and functor definitions for neural activation and mathematical functions.  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cum](/CUM/api/Namespaces/namespacecum/)**  |
| **[cum::functions](/CUM/api/Namespaces/namespacecum_1_1functions/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::functions::Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/)** <br>[Linear]() / identity activation function functor: f(x) = x.  |
| struct | **[cum::functions::GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/)** <br>Gaussian Error [Linear]() Unit activation functor: f(x) = x * P(X <= x).  |
| struct | **[cum::functions::ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/)** <br>Rectified [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit activation functor: f(x) = max(0, x).  |
| struct | **[cum::functions::leaky_ReLU](/CUM/api/Classes/structcum_1_1functions_1_1leaky__ReLU/)** <br>Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x.  |
| struct | **[cum::functions::Tanh](/CUM/api/Classes/structcum_1_1functions_1_1Tanh/)** <br>Hyperbolic tangent activation functor: f(x) = tanh(x).  |
| struct | **[cum::functions::Sigmoid](/CUM/api/Classes/structcum_1_1functions_1_1Sigmoid/)** <br>Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)).  |

## Detailed Description

Master include header and functor definitions for neural activation and mathematical functions. 

Aggregates trigonometric, hyperbolic, exponential, cyclometric, linear units, and logistic modules. 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
