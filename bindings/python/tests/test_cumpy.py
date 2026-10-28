"""Unit tests for the cumpy Python binding."""

import math
import unittest

import cumpy as cp


class TestCumPy(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cp.init(cp.Device.CPU)

    @classmethod
    def tearDownClass(cls) -> None:
        cp.shutdown()

    def assertListAlmostEqual(self, actual: list[float], expected: list[float], places: int = 4) -> None:
        self.assertEqual(len(actual), len(expected))
        for a, b in zip(actual, expected):
            self.assertAlmostEqual(a, b, places=places)

    def test_tensor_arithmetics_and_reductions(self) -> None:
        a = cp.Tensor.from_data((2, 2), [1, 2, 3, 4])
        b = cp.Tensor.from_data((2, 2), [5, 6, 7, 8])

        self.assertEqual(a.shape, (2, 2))
        self.assertEqual(a.rank, 2)
        self.assertEqual(len(a), 4)
        self.assertEqual(a.dtype, cp.DataType.FP32)

        self.assertListAlmostEqual((a + b).to_list(), [6, 8, 10, 12])
        self.assertListAlmostEqual((b - a).to_list(), [4, 4, 4, 4])
        self.assertListAlmostEqual((a * b).to_list(), [5, 12, 21, 32])
        self.assertListAlmostEqual((b / a).to_list(), [5, 3, 7 / 3, 2])
        self.assertListAlmostEqual((a @ b).to_list(), [19, 22, 43, 50])
        self.assertListAlmostEqual((a * 2.0).to_list(), [2, 4, 6, 8])
        self.assertListAlmostEqual((3.0 + a).to_list(), [4, 5, 6, 7])

        c = a.clone()
        c += b
        self.assertListAlmostEqual(c.to_list(), [6, 8, 10, 12])
        c *= 0.5
        self.assertListAlmostEqual(c.to_list(), [3, 4, 5, 6])

        self.assertListAlmostEqual(a.square().to_list(), [1, 4, 9, 16])
        self.assertListAlmostEqual(a.square().sqrt().to_list(), [1, 2, 3, 4])
        self.assertListAlmostEqual(a.clamp(2.0, 3.0).to_list(), [2, 2, 3, 3])

        self.assertAlmostEqual(a.sum(), 10.0, places=4)
        self.assertAlmostEqual(a.mean(), 2.5, places=4)
        self.assertAlmostEqual(a.norm(), math.sqrt(30.0), places=4)

        r = a.reshape((4,))
        self.assertEqual(r.shape, (4,))
        self.assertListAlmostEqual(a.T.to_list(), [1, 3, 2, 4])

        with self.assertRaises(ValueError):
            cp.Tensor((0, 2))

    def test_matrix(self) -> None:
        a = cp.Matrix.from_data(2, 2, [[1, 2], [3, 4]])
        b = cp.Matrix.from_data(2, 2, [5, 6, 7, 8])

        self.assertEqual(a.shape, (2, 2))
        self.assertAlmostEqual(a[0, 1], 2.0)

        self.assertListAlmostEqual((a + b).to_flat_list(), [6, 8, 10, 12])
        self.assertListAlmostEqual((b - a).to_flat_list(), [4, 4, 4, 4])
        self.assertListAlmostEqual((a * b).to_flat_list(), [5, 12, 21, 32])
        self.assertListAlmostEqual((a @ b).to_flat_list(), [19, 22, 43, 50])
        self.assertListAlmostEqual((b / a).to_flat_list(), [5, 3, 7 / 3, 2])
        self.assertListAlmostEqual(a.T.to_flat_list(), [1, 3, 2, 4])

        c = a.clone()
        c[0, 0] = 42.0
        self.assertAlmostEqual(c[0, 0], 42.0)
        self.assertAlmostEqual(a[0, 0], 1.0)

        with self.assertRaises(ValueError):
            _ = a[5, 0]

    def test_vector(self) -> None:
        u = cp.Vector.from_data([1, 2, 3])
        v = cp.Vector.from_data([4, 5, 6])

        self.assertEqual(len(u), 3)
        self.assertAlmostEqual(u[1], 2.0)
        self.assertAlmostEqual(u[-1], 3.0)

        self.assertListAlmostEqual((u + v).to_list(), [5, 7, 9])
        self.assertListAlmostEqual((v - u).to_list(), [3, 3, 3])
        self.assertListAlmostEqual((u * v).to_list(), [4, 10, 18])
        self.assertListAlmostEqual((u * 2.0).to_list(), [2, 4, 6])

        self.assertAlmostEqual(u.dot(v), 32.0, places=4)
        self.assertAlmostEqual(u @ v, 32.0, places=4)
        self.assertAlmostEqual(u.sum(), 6.0, places=4)
        self.assertAlmostEqual(u.norm(), math.sqrt(14.0), places=4)

        w = u.clone()
        w[0] = 10.0
        self.assertAlmostEqual(w[0], 10.0)
        self.assertAlmostEqual(u[0], 1.0)

        with self.assertRaises(ValueError):
            _ = u + cp.Vector.zeros(4)


if __name__ == "__main__":
    unittest.main()
