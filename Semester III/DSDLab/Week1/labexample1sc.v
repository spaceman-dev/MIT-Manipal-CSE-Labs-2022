module labexample1sc(x1,x2,x3,f);
    input x1,x2,x3;
    output f;
    and(a,x1,x2);
    not(b,x2);
    and(c,b,x3);
    or(f,a,c);
endmodule
