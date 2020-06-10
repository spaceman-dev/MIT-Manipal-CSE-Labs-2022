module mux4to1ex1(x0,x1,x2,x3,s0,s1,f);
input x0,x1,x2,x3,s0,s1;
output f;
wire f1,f2;
mux2to1ex1 stage0(x0,x1,s0,f1);
mux2to1ex1 stage1(x2,x3,s0,f2);
mux2to1ex1 stage2(f1,f2,s1,f);
endmodule

module mux2to1ex1(w0,w1,s,f);
input w0,w1,s;
output f;
reg f;
always @(w0 or w1 or s)
begin
if(s==0)
assign f = w0;
else
assign f = w1;
end
endmodule

