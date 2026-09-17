#include "Vmult4.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vmult4* dut = new Vmult4(contextp);

    int fails = 0;
    for (int a = 0; a < 16; a++)
    {
        for (int b = 0; b < 16; b++)
        {
            dut->a = a;
            dut->b = b;
            dut->eval();
            int expectedSum = a * b;
            if (expectedSum == dut->sum)
            {
                printf("PASS: a = %d b = %d expected sum = %d sum = %d\n", a, b, expectedSum, dut->sum);
            }
            else
            {
                fails++;
                printf("FAIL: a = %d b = %d expected sum = %d sum = %d\n", a, b, expectedSum, dut->sum);  
            }
        }
    }
    if (fails > 0)
    {
        printf("%d cases failed\n", fails);
        return 1;
    }
    else
    {
        printf("all cases passed\n");
        return 0;
    }

}