module adder2(
    input logic [1:0] a,
    input logic [1:0] b,
    input logic cin,
    output logic [1:0] sum,
    output logic cout
);

logic cout1;
adder instance1(a[0], b[0], cin, cout1, sum[0]);
adder instance2(a[1], b[1], cout1, cout, sum[1]);



endmodule
