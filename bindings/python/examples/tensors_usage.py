import cumpy as cp


def main() -> None:
    cp.init(cp.Device.CPU)
    try:
        a = cp.Tensor.from_data((2, 3), [1, 2, 3, 4, 5, 6])
        b = cp.Tensor.ones((2, 3)) * 2.0

        print("A       =", a)
        print("B       =", b)
        print("A + B   =", a + b)
        print("A * B   =", a * b)  # elementwise product
        print("A^T     =", a.T)
        print("A @ A^T =", a @ a.T)  # matmul (2x3 @ 3x2 -> 2x2)

        print("sqrt(A) =", a.sqrt())
        print("clamp   =", a.clamp(2.0, 5.0))
        print(f"sum={a.sum():.2f}, mean={a.mean():.2f}, norm={a.norm():.4f}")

        reshaped = a.reshape((3, 2))
        print("reshaped (3, 2) =", reshaped)
    finally:
        cp.shutdown()


if __name__ == "__main__":
    main()
