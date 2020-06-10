module bintogray(b,g);
input [3:0]b;
output [3:0]g;
assign g[3] = b[3];
assign g[0] = b[1]^b[0];
wire [3:0]in;
assign in = 4'b0110;
mux4to1 stage0(in,b[3:2],g[2]);
wire [3:0]in1; 
assign in1 = {(b[1]),(~b[1]),(b[1]),(~b[1])};
mux4to1 stage1(in1,b[3:2],g[1]);
endmodule

module mux4to1(w,s,f);
input [0:3]w;
input [1:0]s;
output f;
assign f = s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
endmodule
