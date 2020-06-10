module penc16to4(w,y,z);
input [15:0]w;
output [3:0]y;
output z;
reg [3:0]y;
reg z;
integer k;
always @(w)
begin
z = 0;
if(w == 0)
y = 0;
else
begin
for(k = 0 ; k < 16 ; k = k + 1)
begin
if(w[k] == 1)
y = k;
end
z = 1;
end
end
endmodule
