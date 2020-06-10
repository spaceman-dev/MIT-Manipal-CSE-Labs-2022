module lab2ex1a(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,h,i,j,k;
assign g = ((~a)&b);
assign h = (c&d);
assign i = (b&(~c)&(~d));
assign j = ((~b)&c);
assign f = (g|h|i|j);
endmodule 
