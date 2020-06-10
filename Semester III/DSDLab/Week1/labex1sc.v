module labex1sc(a,b,c,d,f);
input a,b,c,d;
output f;
and(g,a,b);
or(h,g,c);
not(i,h);
and(j,i,d);
or(k,h,d);
and(f,j,k);
endmodule
