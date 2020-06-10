module labexample1bh(x1,x2,x3,f);
    input x1,x2,x3;
    output f;
    assign f = (x1&x2)|(~x2&x3);
endmodule                                  
