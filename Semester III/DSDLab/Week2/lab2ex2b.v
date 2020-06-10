module lab2ex2b(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,h,i,j;
assign g = ((~a)|b|(~c));
assign h = ((~a)|b|(~d));
assign i = ((~b)|c|d);
assign j = (a|(~c)|d);
assign f = (g&h&i&j);
endmodule 
