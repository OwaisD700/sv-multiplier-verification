// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VAND2__SYMS_H_
#define VERILATED_VAND2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vand2.h"

// INCLUDE MODULE CLASSES
#include "Vand2___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vand2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vand2* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vand2___024root                TOP;

    // CONSTRUCTORS
    Vand2__Syms(VerilatedContext* contextp, const char* namep, Vand2* modelp);
    ~Vand2__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
