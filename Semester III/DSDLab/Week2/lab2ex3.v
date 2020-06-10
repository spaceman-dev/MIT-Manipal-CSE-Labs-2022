module lab2ex3(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
wire a,b,c,d;
assign a = (x1&x2&x3);
assign b = (x1&x2&x4);
assign c = (x2&x3&x4);
assign d = (x1&x3&x4);
assign f = (a|b|c|d);
endmodule 
