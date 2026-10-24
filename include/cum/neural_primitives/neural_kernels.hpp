/**
 * @file neural_kernels.hpp
 * @brief Fused deep learning neural network layer kernels and loss functions.
 * @author jaro
 * @details Implements fused dense feed-forward GEMM + bias + activation layers and binary cross-entropy (BCE) loss.
 */

#pragma once

#include "cum/Core.hpp"
#include "cum/functions/function_id.hpp"

namespace cum::neural_primitives::neural_kernels
{
    /**
     * @brief Computes fused linear feed-forward layer: Y = activation(W * X + B) with batch dimension.
     * @param Y Output activations buffer (out_features x batch).
     * @param W Weight matrix buffer (out_features x in_features).
     * @param X Input feature matrix buffer (in_features x batch).
     * @param B Bias column vector buffer (out_features x 1).
     * @param in_features Number of input features (columns of W, rows of X).
     * @param out_features Number of output features (rows of W, rows of Y).
     * @param batch Batch size (columns of X and Y).
     * @param activation Activation function to apply elementwise (default is linear).
     */
    void feed_forward(cumeric_t* Y, const cumeric_t* W, const cumeric_t* X, const cumeric_t* B, std::size_t in_features, std::size_t out_features, dim_t batch, functions::function_id activation=functions::function_id::linear);

    /**
     * @brief Computes fused linear feed-forward layer for single sample (batch=1).
     * @param Y Output activations buffer.
     * @param W Weight matrix buffer.
     * @param X Input feature buffer.
     * @param B Bias vector buffer.
     * @param in_features Number of input features.
     * @param out_features Number of output features.
     * @param activation Activation function to apply elementwise (default is linear).
     */
    void feed_forward(cumeric_t* Y, const cumeric_t* W, const cumeric_t* X, const cumeric_t* B, std::size_t in_features, std::size_t out_features, functions::function_id activation=functions::function_id::linear);

    /**
     * @brief Computes fused feed-forward layer caching intermediate pre-activation values in @p R.
     * @param Y Output activated buffer.
     * @param R Pre-activation cache buffer (W * X + B).
     * @param W Weight matrix buffer.
     * @param X Input feature buffer.
     * @param B Bias vector buffer.
     * @param in_features Number of input features.
     * @param out_features Number of output features.
     * @param batch Batch size.
     * @param activation Activation function.
     */
    void feed_forward_cached_raw(cumeric_t* Y, cumeric_t* R, const cumeric_t* W, const cumeric_t* X, const cumeric_t* B, std::size_t in_features, std::size_t out_features, size_t batch, functions::function_id activation);

    /**
     * @brief Computes fused feed-forward layer caching pre-activation values for single sample.
     * @param Y Output activated buffer.
     * @param R Pre-activation cache buffer.
     * @param W Weight matrix buffer.
     * @param X Input feature buffer.
     * @param B Bias vector buffer.
     * @param in_features Number of input features.
     * @param out_features Number of output features.
     * @param activation Activation function.
     */
    void feed_forward_cached_raw(cumeric_t* Y, cumeric_t* R, const cumeric_t* W, const cumeric_t* X, const cumeric_t* B, std::size_t in_features, std::size_t out_features, functions::function_id activation);

    /**
     * @brief Backward pass kernel for feed-forward neural layers.
     */
    void feed_backward();

    /**
     * @brief Computes Binary Cross Entropy (BCE) loss and its gradient with respect to predictions.
     * @param grad Output gradient buffer.
     * @param loss Output scalar loss buffer.
     * @param P Predicted probabilities vector buffer in range (0, 1).
     * @param Y Ground truth binary targets vector buffer (0 or 1).
     * @param N Number of elements per batch sample.
     * @param batch Batch size (default 1).
     */
    void BCE(cumeric_t* grad, cumeric_t* loss, const cumeric_t* P, const cumeric_t* Y, dim_t N, dim_t batch=1);

} // namespace cum::neural_primitives::neural_kernels
