---
title: include/cum/functions.hpp
summary: Master include header and functor definitions for neural activation and mathematical functions. 

---

# include/cum/functions.hpp

Master include header and functor definitions for neural activation and mathematical functions.  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cum](Namespaces/namespacecum.md)**  |
| **[cum::functions](Namespaces/namespacecum_1_1functions.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::functions::Linear](Classes/structcum_1_1functions_1_1Linear.md)** <br>[Linear]() / identity activation function functor: f(x) = x.  |
| struct | **[cum::functions::GELU](Classes/structcum_1_1functions_1_1GELU.md)** <br>Gaussian Error [Linear]() Unit activation functor: f(x) = x * P(X <= x).  |
| struct | **[cum::functions::ReLU](Classes/structcum_1_1functions_1_1ReLU.md)** <br>Rectified [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit activation functor: f(x) = max(0, x).  |
| struct | **[cum::functions::leaky_ReLU](Classes/structcum_1_1functions_1_1leaky__ReLU.md)** <br>Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x.  |
| struct | **[cum::functions::Tanh](Classes/structcum_1_1functions_1_1Tanh.md)** <br>Hyperbolic tangent activation functor: f(x) = tanh(x).  |
| struct | **[cum::functions::Sigmoid](Classes/structcum_1_1functions_1_1Sigmoid.md)** <br>Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)).  |

## Detailed Description

Master include header and functor definitions for neural activation and mathematical functions. 

Aggregates trigonometric, hyperbolic, exponential, cyclometric, linear units, and logistic modules. 






-------------------------------

Updated on 2026-10-31 at 18:07:42 +0100
