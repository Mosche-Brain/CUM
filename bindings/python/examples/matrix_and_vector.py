import cumpy as cp


def main() -> None:
    cp.init(cp.Device.CPU)
    try:
        m1 = cp.Matrix.from_data(2, 2, [[1.0, 2.0], [3.0, 4.0]])
        m2 = cp.Matrix.from_data(2, 2, [[5.0, 6.0], [7.0, 8.0]])

        print("M1 =", m1)
        print("M2 =", m2)
        print("M1 + M2 (add)         =", m1 + m2)
        print("M1 * M2 (eltwise mul) =", m1 * m2)
        print("M1 @ M2 (matmul)      =", m1 @ m2)
        print("M1.T                  =", m1.T)

        c = m1.clone()
        c[0, 1] = 10.0
        print("Modyfied copy C[0, 1]=10 ->", c)

        u = cp.Vector.from_data([1.0, 2.0, 3.0])
        v = cp.Vector.from_data([4.0, 5.0, 6.0])
        print("\nu =", u)
        print("v =", v)
        print("u + v   =", u + v)
        print("2.5 * u =", 2.5 * u)
        print(f"u @ v (dot) = {u @ v:.1f}, ||u|| = {u.norm():.4f}")
    finally:
        cp.shutdown()


if __name__ == "__main__":
    main()
