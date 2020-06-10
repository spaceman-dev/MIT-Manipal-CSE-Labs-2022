module graytobinary(gr,bi);
parameter n = 8;
input [n-1:0]gr;
output [n-1:0]bi;
reg [n-1:0]bi;
integer i;
always@(gr)
begin
bi[n-1] = gr[n-1];
for(i=n-2;i>=0;i=i-1)
begin
bi[i] = bi[i+1]^gr[i];
end
end 
endmodule
