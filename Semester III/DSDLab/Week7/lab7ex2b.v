module lab7ex2b(w1,w2,w3,f);
input w1,w2,w3;
output f;
wire s1,s2;
mux2to1ex1 stage0(0,w3,w2,s1);
mux2to1ex1 stage1(w3,1,w2,s2);
mux2to1ex1 stage2(s1,s2,w1,f);
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


