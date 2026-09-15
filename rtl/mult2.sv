module mult2(
    input logic [1:0] a,
    input logic [1:0] b,
    input logic cin,
    output logic[3:0] sum
);

    logic pp0, pp1, pp2, pp3, cout;

    assign pp0 = a[0] & b[0];
    assign pp1 = a[1] & b[0];
    assign pp2 = a[0] & b[1];
    assign pp3 = a[1] & b[1];
    assign sum[0] = pp0 ^ cin;
    adder instance1 (pp1, pp2, (cin & pp0), cout, sum[1]);
    assign sum[2] = pp3 ^ cout;
    assign sum[3] = pp3 & cout;
endmodule
