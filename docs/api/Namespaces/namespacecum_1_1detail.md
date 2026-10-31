---
title: cum::detail

---

# cum::detail



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cum::detail::event_handler](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/)** <br>Factory and accessor bridging SYCL asynchronous events with CUM's [experimental::__event__]().  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](/CUM/api/Classes/classcum_1_1Matrix/)< T, rows_, cols_ > | **[make_matrix_like](/CUM/api/Namespaces/namespacecum_1_1detail/#function-make-matrix-like)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols) |
| template <typename T ,dim_t length_\> <br>[Vector](/CUM/api/Classes/classcum_1_1Vector/)< T, length_ > | **[make_vector_like](/CUM/api/Namespaces/namespacecum_1_1detail/#function-make-vector-like)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) len) |


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

Updated on 2026-10-31 at 18:51:12 +0100