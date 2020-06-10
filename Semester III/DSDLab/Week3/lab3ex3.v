module lab3ex3(x1,x2,x3,x4,x5,f);
input x1,x2,x3,x4,x5;
output f;
wire g,h,i;
assign g = (~x5) |(x1&(~x2));
assign h = ((~x3)&(~x4))|(x3&x4);
assign i = ((~x3)&x4);
assign f = (g&h)|((~g)&i);
endmodule

