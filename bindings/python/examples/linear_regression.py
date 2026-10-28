import cumpy as cp

def main() -> None:
    cp.init(cp.Device.CPU)
    try:
        # 4 probes, 2 feaatures
        x = cp.Tensor.from_data((4, 2), [
            1.0, 2.0,
            2.0, 1.0,
            3.0, 0.5,
            0.5, 3.0,
        ])
        # target: y = 2*x1 - 3*x2
        y_true = cp.Tensor.from_data((4, 1), [
            -4.0,
             1.0,
             4.5,
            -8.0,
        ])

        w = cp.Tensor.zeros((2, 1))
        lr = 0.05
        n = float(x.shape[0])
        x_t = x.T

        for epoch in range(1, 201):
            y_pred = x @ w
            diff = y_pred - y_true
            loss = diff.square().mean()
            # grad = (2 / N) * X^T @ (X @ w - y)
            grad = (x_t @ diff) * (2.0 / n)
            w = w - grad * lr

            if epoch in (1, 10, 50, 100, 200):
                w_vals = w.to_list()
                print(f"epoch {epoch:3d} | MSE = {loss:.6f} | w = [{w_vals[0]:.4f}, {w_vals[1]:.4f}]")

        print("expected weights: [2.0000, -3.0000]")
    finally:
        cp.shutdown()


if __name__ == "__main__":
    main()
