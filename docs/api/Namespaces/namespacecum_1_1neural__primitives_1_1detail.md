---
title: cum::neural_primitives::detail

---

# cum::neural_primitives::detail



## Functions

|                | Name           |
| -------------- | -------------- |
| dnnl::algorithm | **[dnnl_algorithm](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md#function-dnnl-algorithm)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) algorithm) |
| dnnl::prop_kind | **[dnnl_prop_kind](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md#function-dnnl-prop-kind)**([Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) purpose) |
| bool | **[is_backward_purpose](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md#function-is-backward-purpose)**([Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) purpose) |
| bool | **[uses_dst_for_bwd](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md#function-uses-dst-for-bwd)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg) |


## Functions Documentation

### function dnnl_algorithm

```cpp
inline dnnl::algorithm dnnl_algorithm(
    Algo algorithm
)
```


### function dnnl_prop_kind

```cpp
inline dnnl::prop_kind dnnl_prop_kind(
    Purpose purpose
)
```


### function is_backward_purpose

```cpp
bool is_backward_purpose(
    Purpose purpose
)
```


### function uses_dst_for_bwd

```cpp
bool uses_dst_for_bwd(
    Algo alg
)
```






-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100