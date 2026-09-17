# 4-bit Multiplier in SystemVerilog

A 4-bit by 4-bit combinational multiplier written in SystemVerilog, simulated with Verilator, and verified against all 256 input combinations. Every sub-block is exhaustively tested on its own before being used in anything larger.

## Requirements

- Verilator 5.x (developed against 5.050)
- A C++ compiler (`g++`)
- `make`

Builds and runs on Ubuntu.

## Build and test

```bash
make test MODULE=mult4     # build and run the top-level multiplier testbench
make clean                 # remove build output
```

`MODULE=` works for any block in `rtl/`, so `make test MODULE=mult2` or `make test MODULE=adder3` also work. Each testbench exits non-zero if any case fails.

Lint:

```bash
verilator --lint-only -Wall --top-module mult4 rtl/*.sv
```

This is clean under `-Wall` with no waived warnings.

## Design

Each 4-bit input is split into 2-bit halves to form four partial products, which are combined at their correct bit weights:

```
A * B = (A_lo*B_lo) + (A_lo*B_hi + A_hi*B_lo) << 2 + (A_hi*B_hi) << 4
```

Bits 0 and 1 of the result come straight from the lowest partial product and need no addition. The overlapping middle bits are summed through the adder chain, with carries propagated into the upper bits.

Module hierarchy:

```
mult4
├── mult2  x4      2-bit multiply-accumulate (a*b + cin)
│   └── adder      1-bit full adder
├── adder4         4-bit ripple adder
└── adder3         3-bit ripple adder
```

`mult2` takes a carry-in alongside its two operands, computing `a*b + cin`. This lets single carry bits from lower stages be absorbed directly into a partial product instead of needing another adder.

### Why this design

The architecture comes from a 4-bit multiplier I designed in my first year at Imperial for the DECA module, built as a schematic in ISSIE for the [Lab 2 challenge](https://github.com/edstott/EEE1labs/blob/main/DECA/Spring/Lab2-2025/Lab2_2026.pdf). Starting from a design I had already reasoned through gate by gate meant the work here could focus on expressing it correctly in an industry HDL and verifying it properly, rather than inventing an architecture while also learning the language.

## Verification

Every module is tested against an expected value computed independently in C++ using plain integer arithmetic, rather than a restatement of the RTL logic.

| Module | Function | Cases | Result |
|---|---|---|---|
| `adder` | 1-bit full adder | 8 | pass |
| `adder2` | 2-bit ripple adder | 32 | pass |
| `adder3` | 3-bit ripple adder | 128 | pass |
| `adder4` | 4-bit ripple adder | 512 | pass |
| `mult2` | 2-bit multiply-accumulate | 64 | pass |
| `mult4` | 4-bit multiplier | 256 | pass |

Testbenches are C++, driving the Verilator-generated model directly. Each returns a non-zero exit code on failure. This was confirmed by deliberately breaking a module and checking the test caught it, rather than assuming it would.

## What this does not claim

- No synthesis, timing, area or power figures. Verilator is a simulator, so this proves the logic is functionally correct but says nothing about clock frequency, critical path, gate count after synthesis, or behaviour on an FPGA.
- Not UVM. The testbenches are a plain C++ harness and imply no methodology experience with UVM.

## What's next

Scaling to 8-bit by 8-bit, which is 65,536 input combinations and so still exhaustively testable.