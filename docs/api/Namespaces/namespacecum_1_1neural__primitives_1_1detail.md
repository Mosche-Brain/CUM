---
title: cum::neural_primitives::detail

---

# cum::neural_primitives::detail



## Functions

|                | Name           |
| -------------- | -------------- |
| dnnl::algorithm | **[dnnl_algorithm](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1detail/#function-dnnl-algorithm)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) algorithm) |
| dnnl::prop_kind | **[dnnl_prop_kind](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1detail/#function-dnnl-prop-kind)**([Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) purpose) |
| bool | **[is_backward_purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1detail/#function-is-backward-purpose)**([Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) purpose) |
| bool | **[uses_dst_for_bwd](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1detail/#function-uses-dst-for-bwd)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg) |


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

Updated on 2026-10-31 at 18:51:12 +0100