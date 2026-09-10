#include "Vadder2.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv)
{
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    Vadder2* dut = new Vadder2(contextp);

    int fails = 0;

    for (int a = 0; a <= 3; a++) {
        for (int b = 0; b <= 3; b++) {
            for (int c = 0; c <= 1; c++) {

                dut->a   = a;
                dut->b   = b;
                dut->cin = c;      // port is called "cin" in adder2.sv
                dut->eval();

                int total = a + b + c;
                int expected_sum  = total & 3;   // bottom 2 bits -> sum
                int expected_cout = total >> 2;  // whatever's left -> cout

                if (dut->sum != expected_sum || dut->cout != expected_cout) {
                    printf("FAIL: a=%d b=%d cin=%d expected sum=%d cout=%d got sum=%d cout=%d\n",
                           a, b, c, expected_sum, expected_cout, dut->sum, dut->cout);
                    fails++;
                } else {
                    printf("PASS: a=%d b=%d cin=%d -> sum=%d cout=%d\n",
                           a, b, c, dut->sum, dut->cout);
                }
            }
        }
    }

    if (fails > 0) {
        printf("%d case(s) failed\n", fails);
        return 1;
    }
    printf("all 32 cases passed\n");
    return 0;
}