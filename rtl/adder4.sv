module adder4(
    input logic [3:0] a,
    input logic [3:0] b,
    input logic c,
    output logic [3:0] sum,
    output logic cout
);
    logic tmpCout;
    adder2 instance1(a[1:0], b[1:0], c, sum[1:0], tmpCout);
    adder2 instance2(a[3:2], b[3:2], tmpCout, sum[3:2], cout);



endmodule
