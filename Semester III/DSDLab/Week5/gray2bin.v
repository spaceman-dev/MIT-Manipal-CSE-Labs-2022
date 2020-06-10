module gray2bin(g,b);
parameter n=8;
input [n-1:0]g;
output [n-1:0]b;
reg [n-1:0]b;
integer k;
always @(g)
begin 
b[n-1]=g[n-1];
for(k=n-2;k>=0;k=k-1)
begin
b[k]=b[k+1] ^ g[k];
end
end
endmodule
