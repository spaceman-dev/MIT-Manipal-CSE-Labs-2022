module labex2sc(a,b,c,d,f,g);
input a,b,c,d;
output f,g;
nand(h,a,b);
xor(i,h,c);
xor(f,i,d);
nor(g,b,c,d);
endmodule
