module lab2ex1b(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,h,i;
assign g = ((~b)&d);
assign h = ((~b)&c);
assign i = (b&(~c)&(~d));
assign f = (g|h|i);
endmodule 
