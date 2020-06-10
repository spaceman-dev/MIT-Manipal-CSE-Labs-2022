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

