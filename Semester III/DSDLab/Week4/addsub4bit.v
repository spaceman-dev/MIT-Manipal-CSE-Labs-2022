module addsub4bit(Cin,x,y,s,Cout);
input Cin;
input [3:0]x,y;
output Cout;
output [3:0]s;
wire [3:1]c;
wire [3:0]z;
assign z[0] = y[0] ^ Cin;
assign z[1] = y[1] ^ Cin;
assign z[2] = y[2] ^ Cin;
assign z[3] = y[3] ^ Cin;
adder4bit stage0(Cin,x,z,s,Cout);
endmodule

module adder4bit(Cin,x,y,s,Cout);
input Cin;
input [3:0]x;
input [3:0]y;
output [3:0] s;
output Cout;
wire [3:1]c;
fulladd stage0(Cin,x[0],y[0],s[0],c[1]);
fulladd stage1(c[1],x[1],y[1],s[1],c[2]);
fulladd stage2(c[2],x[2],y[2],s[2],c[3]);
fulladd stage3(c[3],x[3],y[3],s[3],Cout);
endmodule

module fulladd(Cin,x,y,s,Cout);
input Cin,x,y;
output s,Cout;
assign s = x^y^Cin;
assign Cout = (x&y)|(x&Cin)|(y&Cin);
endmodule
