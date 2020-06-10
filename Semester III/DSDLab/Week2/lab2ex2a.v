module lab2ex2a(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,h;
assign g = (b|c);
assign h = ((~b)|d);
assign f = (g&h);
endmodule 
