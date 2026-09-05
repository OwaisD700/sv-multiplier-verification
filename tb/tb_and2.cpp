#include "Vand2.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    Vand2* dut = new Vand2(contextp);

    dut->a = 0;
    dut->b = 0;
    dut->eval();

    if (dut->y != 0)
    {
        printf("FAIL: a = 0 b = 0 expected y = 0 got y = %d\n", dut->y);
        return 1;
    }

    printf("PASS: a = 0 b = 0 -> y = %d\n", dut->y);

    dut->a = 1;
    dut->b = 0;
    dut->eval();


    if (dut->y != 0)
    {
        printf("FAIL: a = 1 b = 0 expected y = 0 got y = %d\n", dut->y);
        return 1;
    }
    printf("PASS: a = 1 b = 0 -> y = %d\n", dut->y);

    dut->a = 0;
    dut->b = 1;
    dut->eval();

    if (dut->y != 0)
    {
        printf("FAIL: a = 0 b = 1 expected y = 0 got y = %d\n", dut->y);
        return 1;
    }
    printf("PASS: a = 0 b = 1 -> y = %d\n", dut->y);

    dut->a = 1;
    dut->b = 1;
    dut->eval();

    if (dut->y != 1)
    {
        printf("FAIL: a = 1 b = 1 expected y = 1 got y = %d\n", dut->y);
        return 1;
    }
    printf("PASS: a = 1 b = 1 -> y = %d\n", dut->y);
    




    return 0;
}