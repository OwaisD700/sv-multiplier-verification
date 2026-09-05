// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vand2.h for the primary calling header

#include "Vand2__pch.h"

void Vand2___024root___ctor_var_reset(Vand2___024root* vlSelf);

Vand2___024root::Vand2___024root(Vand2__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vand2___024root___ctor_var_reset(this);
}

void Vand2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vand2___024root::~Vand2___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
