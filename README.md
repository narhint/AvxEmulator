# AvxEmulator

## Overview

Welcome to **AvxEmulator**, a C++ project that serves as a straightforward wrapper around a selection of Intel's SSE2 and AVX2 instruction sets. This emulator is designed to simplify the process of performing basic vector operations—like addition, subtraction, and multiplication—using SIMD (Single Instruction, Multiple Data) instructions. The aim is to make these powerful capabilities accessible to developers without the need to dive deep into the complexities of low-level assembly or intricate CPU architecture.

## Table of Contents

- [Introduction](#introduction)
- [Instruction Set Architecture (ISA)](#instruction-set-architecture-isa)
- [Emulator Design](#emulator-design)
- [Supported Instructions](#supported-instructions)
- [Usage](#usage)
- [Future Aspirations](#future-aspirations)
- [Contributing](#contributing)
- [Documentation and Resources](#documentation-and-resources)
- [License](#license)

## Introduction

SSE2 (Streaming SIMD Extensions 2) and AVX2 (Advanced Vector Extensions 2) are like the secret weapons of modern CPUs, allowing them to process multiple data points simultaneously. Imagine being able to add, subtract, or multiply not just one number at a time, but a whole bunch of them in a single swoop! This is the magic of SIMD, and it’s particularly useful in fields like graphics processing, scientific simulations, and machine learning.

**AvxEmulator** is here to demystify these powerful instruction sets. By wrapping these instructions in a user-friendly interface, we aim to empower developers to harness the full potential of SIMD without getting bogged down in the nitty-gritty details of CPU architecture. Whether you're a seasoned developer or just starting out, this emulator is designed to make your life easier.

## Instruction Set Architecture (ISA)

### SSE2

SSE2 is like the older sibling of SIMD instruction sets, bringing a wealth of capabilities to the table. It operates on 128-bit registers (XMM registers) and allows for a variety of operations, including:

- **Integer Arithmetic**: Think of it as a calculator that can handle multiple numbers at once—addition, subtraction, and multiplication are all in its repertoire.
- **Floating-Point Arithmetic**: Whether you're dealing with whole numbers or decimals, SSE2 has you covered.
- **Data Movement**: Moving data around is a breeze, thanks to load and store operations that shift data between registers and memory.
- **Logical Operations**: Perform bitwise operations like AND, OR, and XOR to manipulate data at the binary level.

### AVX2

AVX2 takes things up a notch. It’s like SSE2 on steroids, introducing 256-bit wide YMM registers that allow for even more data to be processed in parallel. Here’s what makes AVX2 stand out:

- **Fused Multiply-Add (FMA)**: This is where the magic happens—combining multiplication and addition into a single operation, which not only speeds things up but also enhances precision.
- **Gather Operations**: Need to access non-contiguous memory? AVX2 has your back, allowing for efficient data retrieval that can significantly boost performance in certain algorithms.

## Emulator Design

At the heart of **AvxEmulator** is the `AvxEmulator` class, which encapsulates the state of the emulator. It initializes the XMM and YMM registers to zero and provides methods for performing basic arithmetic operations. The design is clean and modular, making it easy to extend and modify.

### Key Components

- **Registers**: The emulator maintains arrays of XMM (128-bit) and YMM (256-bit) registers, simulating the state of the CPU.
- **Emulation Methods**: Each method corresponds to a specific instruction, such as addition, subtraction, or multiplication. These methods utilize intrinsic functions for demonstration purposes.
- **Output Functions**: Helper functions are provided to print the contents of the registers in a human-readable format, making it easy to see the results of your operations.

## Supported Instructions

Currently, **AvxEmulator** supports a handful of essential instructions:

### SSE2 Instructions

- **Addition**: `emulated_sse2_add`
- **Subtraction**: `emulated_sse2_sub`
- **Multiplication**: `emulated_sse2_mul`

### AVX2 Instructions

- **Addition**: `emulated_avx2_add`
- **Subtraction**: `emulated_avx2_sub`
- **Multiplication**: `emulated_avx2_mul`

## Future Adds/Todo list

- Adding more instructions from both SSE2 and AVX2 to broaden the emulator's capabilities.
- Implementing floating-point operations to handle a wider range of mathematical computations.

## Contributing

We welcome contributions to **AvxEmulator**! If you’re passionate about SIMD and want to help improve this project, please fork the repository and submit a pull request. Make sure your code is well-documented and adheres to the project's coding standards.

## Documentation and Resources

For those looking to dive deeper into SIMD and the instruction sets we’re emulating, here are some valuable resources:

- [Intel Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)
- [SSE2 Documentation](https://en.wikipedia.org/wiki/SSE2)
- [AVX2 Documentation](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions#AVX2)

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
