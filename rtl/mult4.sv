module mult4(
    input logic [3:0] a,
    input logic [3:0] b,
    output logic [7:0] sum
);
    logic [3:0] p0, p1, p2, p3;
    logic cin1, cin2;
    mult2 instance1(a[1:0], b[1:0], 0, p0);
    assign sum[1:0] = p0[1:0];
    assign cin1 = p0[2] ^ p0[3]; 
    assign cin2 = p0[3];
    mult2 instance2(a[1:0], b[3:2], cin1, p1);
    mult2 instance3(a[3:2], b[1:0], cin2, p2);
    mult2 instance4(a[3:2], b[3:2], 0, p3);
    logic [3:0] a1;
    logic [2:0] a2, a3;
    adder4 instance5(p1, p2, 0, a1, a2[2]);
    assign sum[3:2] = a1[1:0];
    assign a2[1:0] = a1[3:2];
    assign a3 = p3[2:0];
    logic tmp;
    adder3 instance6(a2, a3, 0, sum[6:4],tmp);
    assign sum[7] = tmp ^ p3[3];





endmodule
