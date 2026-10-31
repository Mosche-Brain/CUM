---
title: cum::detail

---

# cum::detail



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cum::detail::event_handler](Classes/classcum_1_1detail_1_1event__handler.md)** <br>Factory and accessor bridging SYCL asynchronous events with CUM's [experimental::__event__]().  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > | **[make_matrix_like](Namespaces/namespacecum_1_1detail.md#function-make-matrix-like)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[make_vector_like](Namespaces/namespacecum_1_1detail.md#function-make-vector-like)**([dim_t](Namespaces/namespacecum.md#using-dim-t) len) |


## Functions Documentation

### function make_matrix_like

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
Matrix< T, rows_, cols_ > make_matrix_like(
    dim_t rows,
    dim_t cols
)
```


### function make_vector_like

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > make_vector_like(
    dim_t len
)
```






-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100