module mux4to1ex2(w0,w1,w2,w3,s0,s1,f);
input w0,w1,w2,w3,s0,s1;
output f;
assign f = s1?(s0?w3:w2):(s0?w1:w0);
endmodule
