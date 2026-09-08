#include "Vadder.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc,argv);

    Vadder* dut = new Vadder(contextp);

    int fails = 0;

    /// TEST: a = 0, b = 0, c = 0
    /// EXPECTED: sum = 0, cout = 0


    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                dut->a = a;
                dut->b = b;
                dut->c = c;
                dut->eval();

                int total = a + b + c;
                int expected_sum = total & 1;
                int expected_cout = total >> 1;

                if (dut->sum != expected_sum || dut->cout != expected_cout)
                {
                    printf("FAIL: a=%d b=%d c=%d expected sum=%d cout=%d got sum=%d cout=%d\n",
                            a, b, c, expected_sum, expected_cout, dut->sum, dut->cout);
                    fails++;
                }
                else
                {
                    printf("PASS: a=%d b=%d c=%d -> sum=%d cout=%d\n",
                           a, b, c, dut->sum, dut->cout);
                }
            }
        }
    }

    if (fails > 0)
    {
        printf("%d case(s) failed\n", fails);
        return 1;
    }
    printf("all 8 cases passed\n");
    return 0;


}