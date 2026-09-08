module adder(
    input logic a,
    input logic b,
    input logic c,
    output logic cout,
    output logic sum
);

assign sum = a ^ b ^ c;
assign cout = (a&b) | (a&c) | (b&c);

endmodule
