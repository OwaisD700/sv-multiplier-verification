#include "Vmult2.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);

    Vmult2* dut = new Vmult2(contextp);

    int fails = 0;

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                dut->a = a;
                dut->b = b;
                dut->cin = c;
                dut->eval();
                int expected = a * b + c;
                if (dut->sum != expected)
                {
                    fails++;
                    printf("FAIL: a = %d b = %d cin = %d expected sum = %d sum = %d\n", a, b, c, expected, dut->sum);

                }
                else
                {
                    printf("PASS: a = %d b = %d cin = %d expected sum = %d sum = %d\n", a, b, c, expected, dut->sum);
                }
            }
        }
    }

    if (fails > 0)
    {
        printf("%d case(s) failed\n", fails);
        return 1;
    }
    printf("all 64 cases passed\n");
    return 0;
}