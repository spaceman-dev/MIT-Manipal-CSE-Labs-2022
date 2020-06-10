module mux16to1ex3(w,s,f);
input [15:0]w;
input [3:0]s;
wire [1:0]x;
output f;
mux8to1ex3 stage0(w[7:0],s[2:0],x[0]);
mux8to1ex3 stage1(w[15:8],s[2:0],x[1]);
mux2to1ex1 stage2(x[0],x[1],s[3],f);
endmodule
