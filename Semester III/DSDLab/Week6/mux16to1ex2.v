module mux16to1ex2(w,s16,f);
input [0:15]w;
input [3:0]s16;
output f;
wire [0:3]M;
mux4to1ex2 Mux1(w[0],w[1],w[2],w[3],s16[0],s16[1],M[0]);
mux4to1ex2 Mux2(w[4],w[5],w[6],w[7],s16[0],s16[1],M[1]);
mux4to1ex2 Mux3(w[8],w[9],w[10],w[11],s16[0],s16[1],M[2]);
mux4to1ex2 Mux4(w[12],w[13],w[14],w[15],s16[0],s16[1],M[3]);
mux4to1ex2 Mux5(M[0],M[1],M[2],M[3],s16[2],s16[3],f);
endmodule

module mux4to1ex2(w0,w1,w2,w3,s0,s1,f);
input w0,w1,w2,w3,s0,s1;
output f;
assign f = s1?(s0?w3:w2):(s0?w1:w0);
endmodule
