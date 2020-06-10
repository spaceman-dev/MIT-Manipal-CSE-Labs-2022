module dec2to4(w, en, y);
input en;
input [1:0]w;
output [0:3]y;
reg [0:3]y;
always @(w|en)
begin
if ( w == 2'b00 )
y = {en, 3'b000};
else if ( w == 2'b01 )
y = {1'b0, en, 2'b00};
else if ( w == 2'b10 )
y = {2'b00, en, 1'b0};
else if ( w == 2'b11 )
y = {3'b000, en};
end
endmodule
module dec3to8(w, en, y);
input en;
input [2:0]w;
output [0:7]y;
wire [1:0]e;
assign e[0] = en & ~w[2];
assign e[1] = en & w[2];
dec2to4 stage0(w[1:0], e[0], y[0:3]);
dec2to4 stage1(w[1:0], e[1], y[4:7]);
endmodule
