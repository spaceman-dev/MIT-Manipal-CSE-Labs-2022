module mux4to1ex4(w0,w1,w2,w3,s,f);
input w0,w1,w2,w3;
input [1:0]s;
output f;
reg f;
function mux2to1ex4;
input w0,w1,s;
if(s==0)
mux2to1ex4 = w0;
else
mux2to1ex4 = w1;
endfunction
always @(w0 or w1 or w2 or w3 or s)
begin
case (s[1])
0:f=mux2to1ex4(w0,w1,s[0]);
1:f=mux2to1ex4(w2,w3,s[0]);
endcase
end
endmodule


