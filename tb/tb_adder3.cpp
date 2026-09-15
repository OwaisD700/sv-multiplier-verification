#include "Vadder3.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);

    Vadder3* dut = new Vadder3(contextp);

    int fails = 0;

    /// TEST: a = 0, b = 0, c = 0
    /// EXPECTED: sum = 0, cout = 0

    for (int a = 0; a < 8; a++)
    {
        for (int b = 0; b < 8; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                dut->a = a;
                dut->b = b;
                dut->cin = c;
                dut->eval();
                int expectedSum = (a + b + c) % 8;
                int expectedCout = (a + b + c) / 8;
                if (expectedSum != dut->sum || expectedCout != dut->cout)
                {
                    fails++;
                    printf("FAIL: a = %d b = %d cin = %d expected sum = %d sum = %d expected cout = %d cout = %d\n",
                        a, b, c, expectedSum, dut->sum, expectedCout, dut->cout);
                }
                else
                {
                    printf("PASS: a = %d b = %d cin = %d expected sum = %d sum = %d expected cout = %d cout = %d\n",
                        a, b, c, expectedSum, dut->sum, expectedCout, dut->cout);
                }
            }
        }
    }

    if (fails > 0)
    {
        printf("%d case(s) failed\n", fails);
        return 1;
    }
    printf("all cases passed\n");
    return 0;

}