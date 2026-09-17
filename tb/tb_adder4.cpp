#include "Vadder4.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vadder4* dut = new Vadder4(contextp);

    /// standard part complete

    int fails = 0;

    for (int a = 0; a < 16; a++)
    {
        for (int b = 0; b < 16; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                dut->a = a;
                dut->b = b;
                dut->c = c;
                dut->eval();
                int expectedSum = (a + b + c) % (16);
                int expectedCout = (a + b + c) / 16;
                if (expectedSum == dut->sum && expectedCout == dut->cout)
                {
                    printf("PASS: a = %d b = %d cin = %d expected sum = %d sum = %d expected cout = %d cout = %d\n",
                        a, b, c, expectedSum, dut->sum, expectedCout, dut->cout);
                }
                else
                {
                    fails++;
                    printf("FAIL: a = %d b = %d cin = %d expected sum = %d sum = %d expected cout = %d cout = %d\n",
                        a, b, c, expectedSum, dut->sum, expectedCout, dut->cout);
                }
            }
        }
    }
    if (fails > 0)
    {
        printf("%d of cases failed\n", fails);
        return 1;
    }
    else
    {
        printf("All cases passed\n");
        return 0;
    }


}