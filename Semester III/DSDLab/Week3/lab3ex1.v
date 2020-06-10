module lab3ex1(a,b,c,d,f);
input a,b,c,d;
output f;
nand(bn,b,b);
nand(dn,d,d);
nand(e,a,bn);
nand(g,c,dn);
nand(h,e,g);
nand(f,h,h);
endmodule

