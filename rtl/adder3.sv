module adder3(
    input  logic [2:0] a,
    input  logic [2:0] b,
    input  logic       cin,
    output logic [2:0] sum,
    output logic       cout
);
    logic cout1;
    adder2 instance1 (a[1:0],b[1:0],cin,sum[1:0],cout1);
    adder instance2(a[2],b[2],cout1,cout,sum[2]);

endmodule
