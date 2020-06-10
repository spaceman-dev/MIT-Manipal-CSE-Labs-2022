module dec2to43(w,y,en);
input [1:0]w;
input en;
output [3:0]y;
reg [3:0]y;
always @(w or en)
begin
if(en == 0)
y = 15;
else
begin
case (w)
0:y = 14;
1:y = 13;
2:y = 11;
3:y = 7;
endcase
end
end
endmodule
module lab8ex3(w,y,en);
input en;
input [3:0]w;
output [15:0]y;
wire [3:0]x;
dec2to43 stage0(w[3:2],x[3:0],en);
dec2to43 stage1(w[1:0],y[3:0],~x[0]);
dec2to43 stage2(w[1:0],y[7:4],~x[1]);
dec2to43 stage3(w[1:0],y[11:8],~x[2]);
dec2to43 stage4(w[1:0],y[15:12],~x[3]);
endmodule

