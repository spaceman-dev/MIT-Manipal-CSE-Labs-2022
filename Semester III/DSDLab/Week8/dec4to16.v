module dec3to8(w,en,y);
input en;
input [2:0]w;
output [7:0]y;
wire b1,b2;
reg [7:0]y;
integer k;
always @(w or en)
begin
for(k = 0 ; k <= 7 ; k = k + 1)
begin 
if((w == k) && (en == 1))
y[k] = 1;
else
y[k] = 0;
end
end
endmodule
module dec4to16(w,en,y);
input en;
input [3:0]w;
output [15:0]y;
wire b1,b2;
assign b1 = ~w[3] & en;
assign b2 = w[3] & en;
dec3to8 stage0(w[2:0],b1,y[7:0]);
dec3to8 stage1(w[2:0],b2,y[15:8]);
endmodule
