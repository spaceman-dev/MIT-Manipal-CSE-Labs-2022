module multiplier2bit(a,b,p,Cin,Cout);
input [1:0]a,b;
input Cin;
output [3:0]p;
output Cout;
wire [1:0]x,y;
wire c1;
assign p[0] = a[0]&b[0];
assign x[0] = a[1]&b[0];
assign x[1] = 0;
assign y[0] = a[0]&b[1];
assign y[1] = a[1]&b[1];
fulladd stage0(Cin,x[0],y[0],p[1],c1);
fulladd stage1(c1,x[1],y[1],p[2],Cout);
assign p[3] = Cout;
endmodule

module fulladd(Cin,x,y,s,Cout);
input Cin,x,y;
output s,Cout;
assign s = x^y^Cin;
assign Cout = (x&y)|(x&Cin)|(y&Cin);
endmodule

