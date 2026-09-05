#!/usr/bin/env python3
"""Generate the ONNX input models for the SOFIE benchmarks.

The models are built directly with the onnx helper API, using seeded random
weights: only the network architecture matters for benchmarking the
inference speed, so nothing needs to be trained and no binary model files
need to be stored in the repository or downloaded.

The architectures reproduce the models that were originally benchmarked in
PR #239 (and presented at ACAT 2021): parametrized dense and convolutional
networks exported from PyTorch generators (Linear_*, Conv_*, Conv3d_*,
ConvTrans2dModel_*, *_d10_L20_h8_B1), the higgs_model_dense classifier from
the TMVA tutorials, a small ALICE network (SimpleNN_Alice), and fast
simulation models (ConvTModel_G4 and the Generator GAN).

Usage:
    make_input_models.py [--outdir DIR] [model ...]

Without model arguments, all models are generated. --list prints the
available model names.
"""

import argparse
import os
import sys

try:
    import numpy as np
    import onnx
    from onnx import TensorProto, helper, numpy_helper
except ImportError as e:
    print(f"ERROR: missing Python package: {e.name}", file=sys.stderr)
    sys.exit(1)


def _tensor(rng, name, *dims):
    """Random float32 weight initializer."""
    return numpy_helper.from_array(
        rng.standard_normal(dims).astype(np.float32) * 0.1, name=name)


def _pos_tensor(rng, name, *dims):
    """Random strictly positive float32 initializer (e.g. batchnorm variance)."""
    return numpy_helper.from_array(
        rng.uniform(0.5, 1.5, dims).astype(np.float32), name=name)


def _model(name, nodes, inputs, outputs, initializers, opset=9):
    graph = helper.make_graph(nodes, name, inputs, outputs, initializers)
    model = helper.make_model(
        graph, opset_imports=[helper.make_opsetid("", opset)])
    onnx.checker.check_model(model)
    return model


def _finfo(name, shape):
    return helper.make_tensor_value_info(name, TensorProto.FLOAT, shape)


def make_linear(batch_size):
    """Dense network with ten Gemm+Relu layers: 100 -> 8x50 -> 10."""
    rng = np.random.default_rng(16)
    widths = [100] + 9 * [50] + [10]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(widths[:-1], widths[1:])):
        inits += [_tensor(rng, f"w{i}", n_out, n_in), _tensor(rng, f"b{i}", n_out)]
        last = i == len(widths) - 2
        out = "output" if last else f"gemm{i}"
        nodes.append(helper.make_node("Gemm", [x, f"w{i}", f"b{i}"], [out], transB=1))
        if not last:
            nodes.append(helper.make_node("Relu", [out], [f"relu{i}"]))
            x = f"relu{i}"
    return _model("Linear", nodes,
                  [_finfo("input", [batch_size, 100])],
                  [_finfo("output", [batch_size, 10])], inits)


def make_generator(batch_size):
    """Dense GAN generator: 14 -> 14 -> 20 -> 50 -> 100 -> 40500, with
    batch normalization after each hidden layer and a Sigmoid output."""
    rng = np.random.default_rng(17)
    widths = [14, 14, 20, 50, 100, 40500]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(widths[:-1], widths[1:])):
        # keras2onnx-style Gemm with the weight matrix stored as (in, out)
        inits += [_tensor(rng, f"w{i}", n_in, n_out), _tensor(rng, f"b{i}", n_out)]
        nodes.append(helper.make_node("Gemm", [x, f"w{i}", f"b{i}"], [f"gemm{i}"]))
        x = f"gemm{i}"
        if i < len(widths) - 2:
            nodes.append(helper.make_node("Relu", [x], [f"relu{i}"]))
            inits += [_tensor(rng, f"scale{i}", n_out), _tensor(rng, f"beta{i}", n_out),
                      _tensor(rng, f"mean{i}", n_out), _pos_tensor(rng, f"var{i}", n_out)]
            nodes.append(helper.make_node(
                "BatchNormalization",
                [f"relu{i}", f"scale{i}", f"beta{i}", f"mean{i}", f"var{i}"],
                [f"bn{i}"], epsilon=1e-6))
            x = f"bn{i}"
    nodes.append(helper.make_node("Sigmoid", [x], ["output"]))
    return _model("Generator", nodes,
                  [_finfo("input", [batch_size, 14])],
                  [_finfo("output", [batch_size, 40500])], inits)


def make_conv2d(nlayers, batch_size, pads):
    """Chain of 5x5 Conv+Relu layers on a 100x100 image, with the channel
    count doubling up to 128 in the middle of the chain and halving back to
    one at the end (for nlayers=14), or a single 1->2 channel layer."""
    rng = np.random.default_rng(18)
    if nlayers == 1:
        channels = [1, 2]
    else:
        channels = [1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2, 1]
    assert len(channels) == nlayers + 1
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(channels[:-1], channels[1:])):
        inits += [_tensor(rng, f"w{i}", n_out, n_in, 5, 5), _tensor(rng, f"b{i}", n_out)]
        nodes.append(helper.make_node(
            "Conv", [x, f"w{i}", f"b{i}"], [f"conv{i}"],
            kernel_shape=[5, 5], pads=4 * [pads], strides=[1, 1]))
        out = "output" if i == nlayers - 1 else f"relu{i}"
        nodes.append(helper.make_node("Relu", [f"conv{i}"], [out]))
        x = out
    d_out = 100 if pads == 2 else 100 - nlayers * 4
    return _model("Conv2d", nodes,
                  [_finfo("input", [batch_size, 1, 100, 100])],
                  [_finfo("output", [batch_size, channels[-1], d_out, d_out])], inits)


def make_conv3d():
    """3d convolutional network on a 32x32x32 volume: four 5x5x5 Conv+Relu
    layers, a strided 6x6x6 pooling convolution, and a dense layer."""
    rng = np.random.default_rng(19)
    channels = [1, 32, 8, 8, 8]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(channels[:-1], channels[1:])):
        inits += [_tensor(rng, f"w{i}", n_out, n_in, 5, 5, 5), _tensor(rng, f"b{i}", n_out)]
        nodes.append(helper.make_node(
            "Conv", [x, f"w{i}", f"b{i}"], [f"conv{i}"],
            kernel_shape=[5, 5, 5], pads=6 * [1], strides=[1, 1, 1]))
        nodes.append(helper.make_node("Relu", [f"conv{i}"], [f"relu{i}"]))
        x = f"relu{i}"
    inits += [_tensor(rng, "wpool", 4, 8, 6, 6, 6), _tensor(rng, "bpool", 4)]
    nodes.append(helper.make_node(
        "Conv", [x, "wpool", "bpool"], ["convpool"],
        kernel_shape=[6, 6, 6], pads=6 * [0], strides=[6, 6, 6]))
    nodes.append(helper.make_node("Relu", ["convpool"], ["relupool"]))
    nodes.append(helper.make_node("Flatten", ["relupool"], ["flat"], axis=1))
    inits += [_tensor(rng, "wfc", 8, 256), _tensor(rng, "bfc", 8)]
    nodes.append(helper.make_node("Gemm", ["flat", "wfc", "bfc"], ["output"], transB=1))
    return _model("Conv3d", nodes,
                  [_finfo("input", [1, 1, 32, 32, 32])],
                  [_finfo("output", [1, 8])], inits)


def make_convtrans2d():
    """Small chain of four ConvTranspose layers with Relu in between."""
    rng = np.random.default_rng(20)
    # (in channels, out channels, kernel size, pads, strides)
    layers = [(1, 4, 2, 1, 1), (4, 8, 3, 1, 1), (8, 4, 3, 1, 1), (4, 1, 2, 0, 2)]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out, k, p, s) in enumerate(layers):
        inits += [_tensor(rng, f"w{i}", n_in, n_out, k, k), _tensor(rng, f"b{i}", n_out)]
        last = i == len(layers) - 1
        out = "output" if last else f"conv{i}"
        nodes.append(helper.make_node(
            "ConvTranspose", [x, f"w{i}", f"b{i}"], [out],
            kernel_shape=[k, k], pads=4 * [p], strides=[s, s]))
        if not last:
            nodes.append(helper.make_node("Relu", [out], [f"relu{i}"]))
            x = f"relu{i}"
    return _model("ConvTrans2d", nodes,
                  [_finfo("input", [1, 1, 4, 4])],
                  [_finfo("output", [1, 1, 6, 6])], inits)


def make_convt_g4():
    """Fast simulation model: a dense layer inflates 15 inputs to a 3x11
    image with 180 channels, which three ConvTranspose layers upscale to
    18 channels of 18x50 (in channels-last output layout)."""
    rng = np.random.default_rng(21)
    nodes = [helper.make_node("Gemm", ["input", "wfc", "bfc"], ["fc"], transB=1),
             helper.make_node("Relu", ["fc"], ["fcrelu"]),
             helper.make_node("Reshape", ["fcrelu", "shape"], ["reshaped"]),
             helper.make_node("Transpose", ["reshaped"], ["nchw"], perm=[0, 3, 1, 2])]
    inits = [_tensor(rng, "wfc", 5940, 15), _tensor(rng, "bfc", 5940),
             numpy_helper.from_array(np.array([1, 3, 11, 180], dtype=np.int64), name="shape")]
    # (in channels, out channels, kernel size, strides)
    layers = [(180, 180, 3, 2), (180, 90, 3, 2), (90, 45, 4, 1)]
    x = "nchw"
    for i, (n_in, n_out, k, s) in enumerate(layers):
        inits += [_tensor(rng, f"w{i}", n_in, n_out, k, k), _tensor(rng, f"b{i}", n_out)]
        nodes.append(helper.make_node(
            "ConvTranspose", [x, f"w{i}", f"b{i}"], [f"conv{i}"],
            kernel_shape=[k, k], pads=[0, 0, 0, 0], strides=[s, s]))
        x = f"conv{i}"
        if i < len(layers) - 1:
            nodes.append(helper.make_node("Relu", [x], [f"relu{i}"]))
            x = f"relu{i}"
    nodes.append(helper.make_node("Sigmoid", [x], ["sigmoid"]))
    nodes.append(helper.make_node("Transpose", ["sigmoid"], ["output"], perm=[0, 3, 1, 2]))
    return _model("ConvTModel_G4", nodes,
                  [_finfo("input", [1, 15])],
                  [_finfo("output", [1, 50, 45, 18])], inits)


def make_simplenn_alice():
    """Small dense network with LeakyRelu activations and no batch dimension."""
    rng = np.random.default_rng(22)
    widths = [16, 100, 50, 1]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(widths[:-1], widths[1:])):
        inits += [_tensor(rng, f"w{i}", n_in, n_out), _tensor(rng, f"b{i}", n_out)]
        last = i == len(widths) - 2
        out = "output" if last else f"add{i}"
        nodes.append(helper.make_node("MatMul", [x, f"w{i}"], [f"matmul{i}"]))
        nodes.append(helper.make_node("Add", [f"b{i}", f"matmul{i}"], [out]))
        if not last:
            nodes.append(helper.make_node("LeakyRelu", [out], [f"lrelu{i}"], alpha=0.01))
            x = f"lrelu{i}"
    return _model("SimpleNN_Alice", nodes,
                  [_finfo("input", [16])], [_finfo("output", [1])], inits)


def make_higgs_model_dense():
    """The dense Higgs classifier from the TMVA tutorials: 7 -> 5x100 -> 2
    with Relu activations and a Sigmoid output."""
    rng = np.random.default_rng(23)
    widths = [7] + 5 * [100] + [2]
    nodes, inits = [], []
    x = "input"
    for i, (n_in, n_out) in enumerate(zip(widths[:-1], widths[1:])):
        # keras2onnx-style Gemm with the weight matrix stored as (in, out)
        inits += [_tensor(rng, f"w{i}", n_in, n_out), _tensor(rng, f"b{i}", n_out)]
        nodes.append(helper.make_node("Gemm", [x, f"w{i}", f"b{i}"], [f"gemm{i}"]))
        x = f"gemm{i}"
        if i < len(widths) - 2:
            nodes.append(helper.make_node("Relu", [x], [f"relu{i}"]))
            x = f"relu{i}"
    nodes.append(helper.make_node("Sigmoid", [x], ["output"]))
    return _model("higgs_model_dense", nodes,
                  [_finfo("input", [1, 7])], [_finfo("output", [1, 2])], inits)


def make_recurrent(op_type):
    """Recurrent network (RNN, GRU, or LSTM) with 10 inputs, 20 time steps,
    and a hidden size of 8, followed by a dense layer on the last step."""
    rng = np.random.default_rng(24)
    d, t, h = 10, 20, 8
    ngates = {"RNN": 1, "GRU": 3, "LSTM": 4}[op_type]
    rec_inputs = ["xt", "w", "r", "bias", "", "h0"]
    rec_outputs = ["y", "yh"]
    inits = [_tensor(rng, "w", 1, ngates * h, d), _tensor(rng, "r", 1, ngates * h, h),
             _tensor(rng, "bias", 1, 2 * ngates * h), _tensor(rng, "h0", 1, 1, h),
             _tensor(rng, "wfc", 2, h), _tensor(rng, "bfc", 2)]
    kwargs = {"hidden_size": h}
    if op_type == "GRU":
        kwargs["linear_before_reset"] = 1
    if op_type == "LSTM":
        rec_inputs.append("c0")
        rec_outputs.append("yc")
        inits.append(_tensor(rng, "c0", 1, 1, h))
    nodes = [
        helper.make_node("Transpose", ["input"], ["xt"], perm=[1, 0, 2]),
        helper.make_node(op_type, rec_inputs, rec_outputs, **kwargs),
        helper.make_node("Squeeze", ["y"], ["squeezed"], axes=[1]),
        helper.make_node("Transpose", ["squeezed"], ["batchfirst"], perm=[1, 0, 2]),
        helper.make_node("Slice", ["batchfirst"], ["laststep"],
                         axes=[1], starts=[-1], ends=[np.iinfo(np.int64).max]),
        helper.make_node("Squeeze", ["laststep"], ["flat"], axes=[1]),
        helper.make_node("Gemm", ["flat", "wfc", "bfc"], ["output"], transB=1),
    ]
    return _model(op_type, nodes,
                  [_finfo("input", [1, t, d])], [_finfo("output", [1, 2])], inits)


MODELS = {
    "Linear_16": lambda: make_linear(16),
    "Linear_32": lambda: make_linear(32),
    "Linear_64": lambda: make_linear(64),
    "Linear_event": lambda: make_linear(1),
    "Generator_B1": lambda: make_generator(1),
    "Generator_B64": lambda: make_generator(64),
    "Conv_d100_L1_B1": lambda: make_conv2d(1, 1, pads=2),
    "Conv_d100_L14_B1": lambda: make_conv2d(14, 1, pads=2),
    "Conv_d100_L14_B32": lambda: make_conv2d(14, 32, pads=0),
    "Conv3d_d32_L4_B1": make_conv3d,
    "ConvTrans2dModel_B1": make_convtrans2d,
    "ConvTModel_G4": make_convt_g4,
    "SimpleNN_Alice": make_simplenn_alice,
    "higgs_model_dense": make_higgs_model_dense,
    "RNN_d10_L20_h8_B1": lambda: make_recurrent("RNN"),
    "GRU_d10_L20_h8_B1": lambda: make_recurrent("GRU"),
    "LSTM_d10_L20_h8_B1": lambda: make_recurrent("LSTM"),
}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("models", nargs="*", help="models to generate (default: all)")
    parser.add_argument("--outdir", default=".", help="output directory")
    parser.add_argument("--list", action="store_true", help="list available models")
    args = parser.parse_args()

    if args.list:
        print("\n".join(MODELS))
        return

    names = args.models or list(MODELS)
    for name in names:
        if name not in MODELS:
            parser.error(f"unknown model {name} (--list shows the available ones)")

    os.makedirs(args.outdir, exist_ok=True)
    for name in names:
        path = os.path.join(args.outdir, f"{name}.onnx")
        onnx.save(MODELS[name](), path)
        print(f"generated {path}")


if __name__ == "__main__":
    main()
