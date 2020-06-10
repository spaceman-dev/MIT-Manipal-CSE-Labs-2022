module bcdtoex3(bcd,ex3);
input [3:0]bcd;
output [3:0]ex3;
assign ex3[0] = ~bcd[0];
wire [0:7]in;
assign in = {(2'b00),(bcd[0]),(5'b11000)};
mux8to1 stage0(in,bcd[3:1],ex3[3]);
wire [0:7] in1;
assign in1 = {(bcd[0],(1'b1),(~bcd[0]),(1'b0),(bcd[0]),(3'b000)};
mux8to1  stage1(in1,bcd[3:1],ex3[2]);
wire [0:7]in2;
assign in2 = {(~bcd[0]),(bcd[0]),(~bcd[0]),(bcd[0]),(~bcd[0]),(3'b000)};
mux8to1 stage2(in2,bcd[3:1],ex3[1]);
endmodule
