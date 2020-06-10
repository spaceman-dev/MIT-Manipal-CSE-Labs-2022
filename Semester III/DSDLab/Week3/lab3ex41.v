module lab3ex41(a,b,c,d,f);
input a,b,c,d;
output f;
nor(dn,d,d);
nor(e,a,dn);
nor(g,c,dn);
nor(h,e,g);
nor(f,h,h);
endmodule
