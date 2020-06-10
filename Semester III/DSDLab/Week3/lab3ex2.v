module lab3ex2(a,b,c,d,f);
input a,b,c,d;
output f;
nor(bn,b,b);
nor(dn,d,d);
nor(e,a,dn,c);
nor(g,b,d);
nor(h,b,c);
nor(i,e,g,h);
nor(f,i,i);
endmodule

