// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vand2.h for the primary calling header

#ifndef VERILATED_VAND2___024ROOT_H_
#define VERILATED_VAND2___024ROOT_H_  // guard

#include "verilated.h"


class Vand2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vand2___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(y,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__a__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__b__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __VicoPhaseResult;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    Vand2__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vand2___024root(Vand2__Syms* symsp, const char* namep);
    ~Vand2___024root();
    VL_UNCOPYABLE(Vand2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
