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

    def test_dnn_oop_descriptors_memory_and_primitives(self) -> None:
        md = cp.dnn.MemoryDescriptor((2, 3), cp.DataType.FP32, cp.Layout.AB)
        self.assertTrue(md.valid)
        self.assertEqual(md.shape, (2, 3))
        self.assertEqual(md.strides, (3, 1))
        self.assertEqual(md.size, 24)
        self.assertEqual(md, md.clone())
        self.assertNotEqual(md, md.reshape((3, 2)))

        mem = cp.dnn.Memory(md).copy_from_list([1, 2, 3, 4, 5, 6])
        self.assertListAlmostEqual(mem.to_list(), [1, 2, 3, 4, 5, 6])
        view_md = cp.dnn.MemoryDescriptor.from_strides((3, 2), (2, 1), cp.DataType.FP32)
        view_mem = cp.dnn.Memory.view(view_md, mem)
        self.assertListAlmostEqual(view_mem.to_list(), [1, 2, 3, 4, 5, 6])

        # Matmul with Layout.ANY + bias + async Event chaining into LeakyReLU
        a = cp.Tensor.from_data((2, 2), [1.0, -2.0, -3.0, 1.0])
        b = cp.Tensor.from_data((2, 2), [2.0, 1.0, 1.0, 3.0])
        bias = cp.Tensor.from_data((1, 2), [-1.0, 0.5])
        any_dst = cp.dnn.MemoryDescriptor.any((2, 2), cp.DataType.FP32)

        mm_pd = cp.dnn.PrimitiveDescriptor.matmul(any_dst, a, b, bias)
        self.assertEqual(mm_pd.kind, cp.dnn.PrimitiveKind.MATMUL)
        self.assertTrue(len(mm_pd.impl_info) > 0)

        mm_out = cp.Tensor.from_descriptor(mm_pd.dst_desc())
        act_out = cp.Tensor.from_descriptor(mm_pd.dst_desc())

        mm_prim = cp.dnn.Primitive(mm_pd)
        relu_pd = cp.dnn.PrimitiveDescriptor.eltwise_forward(
            cp.dnn.Algo.ELTWISE_LEAKY_RELU, mm_out, mm_out, alpha=0.1
        )
        relu_prim = cp.dnn.Primitive(relu_pd)

        ev1 = mm_prim(dst=mm_out, src=a, weights=b, bias=bias, async_op=True)
        self.assertIsInstance(ev1, cp.Event)
        ev2 = relu_prim(act_out, mm_out, deps=[ev1], async_op=True)
        self.assertIsInstance(ev2, cp.Event)
        ev2.wait()

        self.assertListAlmostEqual(act_out.to_list(), [-0.1, -0.45, -0.6, 0.5])

        # Explicit Argument map execution on Concat
        x0 = cp.Tensor.from_data((2, 1), [10.0, 20.0])
        x1 = cp.Tensor.from_data((2, 2), [1.0, 2.0, 3.0, 4.0])
        cat_pd = cp.dnn.PrimitiveDescriptor.concat([x0, x1], axis=1)
        cat_out = cp.Tensor.from_descriptor(cat_pd.dst_desc())
        cat_prim = cp.dnn.Primitive(cat_pd)
        cat_prim(
            args={
                cp.dnn.Argument.DST: cat_out,
                cp.dnn.Argument.multiple_src_at(0): x0,
                cp.dnn.Argument.multiple_src_at(1): x1,
            }
        )
        self.assertEqual(cat_out.shape, (2, 3))
        self.assertListAlmostEqual(cat_out.to_list(), [10.0, 1.0, 2.0, 20.0, 3.0, 4.0])

    def test_dnn_functional_layers_and_backward(self) -> None:
        # Activations + backward
        x = cp.Tensor.from_data((4,), [-2.0, -0.5, 0.0, 3.0])
        dy = cp.Tensor.from_data((4,), [1.0, 2.0, 3.0, 4.0])
        y = cp.dnn.leaky_relu(x, negative_slope=0.1)
        self.assertListAlmostEqual(y.to_list(), [-0.2, -0.05, 0.0, 3.0])

        dx = cp.dnn.leaky_relu_backward(dy, x, negative_slope=0.1)
        self.assertListAlmostEqual(dx.to_list(), [0.1, 0.2, 0.3, 4.0])

        sig = cp.dnn.sigmoid(cp.Tensor.from_data((2,), [0.0, math.log(3.0)]))
        self.assertListAlmostEqual(sig.to_list(), [0.5, 0.75])
        dsig = cp.dnn.sigmoid_backward(
            cp.Tensor.from_data((2,), [1.0, 1.0]), sig, use_dst=True
        )
        self.assertListAlmostEqual(dsig.to_list(), [0.25, 0.1875])

        # Broadcast binary ops with rank mismatch (2, 3) + (3,)
        m = cp.Tensor.from_data((2, 3), [1, 2, 3, 4, 5, 6])
        row = cp.Tensor.from_data((3,), [10, 20, 30])
        added = cp.dnn.add(m, row)
        self.assertEqual(added.shape, (2, 3))
        self.assertListAlmostEqual(added.to_list(), [11, 22, 33, 14, 25, 36])

        # PyTorch-style linear(input, weight[out, in], bias[out]) on 2D and batched 3D inputs
        inp = cp.Tensor.from_data((2, 3), [1, 2, 3, 4, 5, 6])
        w = cp.Tensor.from_data((2, 3), [1, 0, -1, 2, 1, 0])  # out_features=2, in_features=3
        b = cp.Tensor.from_data((2,), [0.5, -1.0])
        lin = cp.dnn.linear(inp, w, b)
        self.assertEqual(lin.shape, (2, 2))
        # Row 0: [1*1 + 2*0 + 3*(-1) + 0.5, 1*2 + 2*1 + 3*0 - 1.0] = [-1.5, 3.0]
        # Row 1: [4*1 + 5*0 + 6*(-1) + 0.5, 4*2 + 5*1 + 6*0 - 1.0] = [-1.5, 12.0]
        self.assertListAlmostEqual(lin.to_list(), [-1.5, 3.0, -1.5, 12.0])

        inp3d = inp.reshape((1, 2, 3))
        lin3d, ev = cp.dnn.linear(inp3d, w, b, async_op=True)
        ev.wait()
        self.assertEqual(lin3d.shape, (1, 2, 2))
        self.assertListAlmostEqual(lin3d.to_list(), [-1.5, 3.0, -1.5, 12.0])

        # Softmax + Softmax backward
        logits = cp.Tensor.from_data((1, 3), [0.0, math.log(2.0), math.log(5.0)])
        probs = cp.dnn.softmax(logits, axis=-1)
        self.assertListAlmostEqual(probs.to_list(), [0.125, 0.25, 0.625])
        grad_p = cp.Tensor.from_data((1, 3), [1.0, 0.0, 0.0])
        grad_logits = cp.dnn.softmax_backward(grad_p, probs, axis=-1)
        # s_i * (g_i - sum_j s_j g_j), dot = 0.125 -> [0.125*0.875, -0.25*0.125, -0.625*0.125]
        self.assertListAlmostEqual(
            grad_logits.to_list(), [0.109375, -0.03125, -0.078125]
        )

        # Reductions (keepdims=False and keepdims=True)
        r_sum = cp.dnn.reduce_sum(m, axis=1)
        self.assertEqual(r_sum.shape, (2,))
        self.assertListAlmostEqual(r_sum.to_list(), [6.0, 15.0])

        r_mean = cp.dnn.reduce_mean(m, axis=0, keepdims=True)
        self.assertEqual(r_mean.shape, (1, 3))
        self.assertListAlmostEqual(r_mean.to_list(), [2.5, 3.5, 4.5])

        # Multi-tensor sum, concat, and reorder (layout + S32 dtype)
        s = cp.dnn.sum_tensors([m, m], scales=[2.0, -0.5])
        self.assertListAlmostEqual(s.to_list(), [1.5, 3.0, 4.5, 6.0, 7.5, 9.0])

        cat = cp.dnn.concat([m, m], axis=0)
        self.assertEqual(cat.shape, (4, 3))

        reord_s32 = cp.dnn.reorder(m, dtype=cp.DataType.S32, layout=cp.Layout.BA)
        self.assertEqual(reord_s32.dtype, cp.DataType.S32)
        self.assertEqual(reord_s32.layout, cp.Layout.BA)
        # Physical buffer in BA (column-major for 2x3): [1, 4, 2, 5, 3, 6]
        self.assertEqual(reord_s32.to_list(), [1, 4, 2, 5, 3, 6])


if __name__ == "__main__":
    unittest.main()
