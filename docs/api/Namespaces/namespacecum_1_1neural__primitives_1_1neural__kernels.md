---
title: cum::neural_primitives::neural_kernels

---

# cum::neural_primitives::neural_kernels



## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[feed_forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-feed-forward)**(cumeric_t * Y, const cumeric_t * W, const cumeric_t * X, const cumeric_t * B, std::size_t in_features, std::size_t out_features, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) batch, [functions::function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation =[functions::function_id::linear](/CUM/api/Namespaces/namespacecum_1_1functions/#enumvalue-linear))<br>Computes fused linear feed-forward layer: Y = activation(W * X + B) with batch dimension.  |
| void | **[feed_forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-feed-forward)**(cumeric_t * Y, const cumeric_t * W, const cumeric_t * X, const cumeric_t * B, std::size_t in_features, std::size_t out_features, [functions::function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation =[functions::function_id::linear](/CUM/api/Namespaces/namespacecum_1_1functions/#enumvalue-linear))<br>Computes fused linear feed-forward layer for single sample (batch=1).  |
| void | **[feed_forward_cached_raw](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-feed-forward-cached-raw)**(cumeric_t * Y, cumeric_t * R, const cumeric_t * W, const cumeric_t * X, const cumeric_t * B, std::size_t in_features, std::size_t out_features, size_t batch, [functions::function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Computes fused feed-forward layer caching intermediate pre-activation values in `R`.  |
| void | **[feed_forward_cached_raw](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-feed-forward-cached-raw)**(cumeric_t * Y, cumeric_t * R, const cumeric_t * W, const cumeric_t * X, const cumeric_t * B, std::size_t in_features, std::size_t out_features, [functions::function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Computes fused feed-forward layer caching pre-activation values for single sample.  |
| void | **[feed_backward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-feed-backward)**()<br>Backward pass kernel for feed-forward neural layers.  |
| void | **[BCE](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/#function-bce)**(cumeric_t * grad, cumeric_t * loss, const cumeric_t * P, const cumeric_t * Y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) batch =1)<br>Computes Binary Cross Entropy (BCE) loss and its gradient with respect to predictions.  |


## Functions Documentation

### function feed_forward

```cpp
void feed_forward(
    cumeric_t * Y,
    const cumeric_t * W,
    const cumeric_t * X,
    const cumeric_t * B,
    std::size_t in_features,
    std::size_t out_features,
    dim_t batch,
    functions::function_id activation =functions::function_id::linear
)
```

Computes fused linear feed-forward layer: Y = activation(W * X + B) with batch dimension. 

**Parameters**: 

  * **Y** Output activations buffer (out_features x batch). 
  * **W** Weight matrix buffer (out_features x in_features). 
  * **X** Input feature matrix buffer (in_features x batch). 
  * **B** Bias column vector buffer (out_features x 1). 
  * **in_features** Number of input features (columns of W, rows of X). 
  * **out_features** Number of output features (rows of W, rows of Y). 
  * **batch** Batch size (columns of X and Y). 
  * **activation** Activation function to apply elementwise (default is linear). 


### function feed_forward

```cpp
void feed_forward(
    cumeric_t * Y,
    const cumeric_t * W,
    const cumeric_t * X,
    const cumeric_t * B,
    std::size_t in_features,
    std::size_t out_features,
    functions::function_id activation =functions::function_id::linear
)
```

Computes fused linear feed-forward layer for single sample (batch=1). 

**Parameters**: 

  * **Y** Output activations buffer. 
  * **W** Weight matrix buffer. 
  * **X** Input feature buffer. 
  * **B** Bias vector buffer. 
  * **in_features** Number of input features. 
  * **out_features** Number of output features. 
  * **activation** Activation function to apply elementwise (default is linear). 


### function feed_forward_cached_raw

```cpp
void feed_forward_cached_raw(
    cumeric_t * Y,
    cumeric_t * R,
    const cumeric_t * W,
    const cumeric_t * X,
    const cumeric_t * B,
    std::size_t in_features,
    std::size_t out_features,
    size_t batch,
    functions::function_id activation
)
```

Computes fused feed-forward layer caching intermediate pre-activation values in `R`. 

**Parameters**: 

  * **Y** Output activated buffer. 
  * **R** Pre-activation cache buffer (W * X + B). 
  * **W** Weight matrix buffer. 
  * **X** Input feature buffer. 
  * **B** Bias vector buffer. 
  * **in_features** Number of input features. 
  * **out_features** Number of output features. 
  * **batch** Batch size. 
  * **activation** Activation function. 


### function feed_forward_cached_raw

```cpp
void feed_forward_cached_raw(
    cumeric_t * Y,
    cumeric_t * R,
    const cumeric_t * W,
    const cumeric_t * X,
    const cumeric_t * B,
    std::size_t in_features,
    std::size_t out_features,
    functions::function_id activation
)
```

Computes fused feed-forward layer caching pre-activation values for single sample. 

**Parameters**: 

  * **Y** Output activated buffer. 
  * **R** Pre-activation cache buffer. 
  * **W** Weight matrix buffer. 
  * **X** Input feature buffer. 
  * **B** Bias vector buffer. 
  * **in_features** Number of input features. 
  * **out_features** Number of output features. 
  * **activation** Activation function. 


### function feed_backward

```cpp
void feed_backward()
```

Backward pass kernel for feed-forward neural layers. 

### function BCE

```cpp
void BCE(
    cumeric_t * grad,
    cumeric_t * loss,
    const cumeric_t * P,
    const cumeric_t * Y,
    dim_t N,
    dim_t batch =1
)
```

Computes Binary Cross Entropy (BCE) loss and its gradient with respect to predictions. 

**Parameters**: 

  * **grad** Output gradient buffer. 
  * **loss** Output scalar loss buffer. 
  * **P** Predicted probabilities vector buffer in range (0, 1). 
  * **Y** Ground truth binary targets vector buffer (0 or 1). 
  * **N** Number of elements per batch sample. 
  * **batch** Batch size (default 1). 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100