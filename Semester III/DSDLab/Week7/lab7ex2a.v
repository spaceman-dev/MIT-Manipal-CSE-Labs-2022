module lab7ex2a(w1,w2,w3,f);
input w1,w2,w3;
output f;
mux2to1ex1 stage0((w2&w3),(w2|w3),w1,f);
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


