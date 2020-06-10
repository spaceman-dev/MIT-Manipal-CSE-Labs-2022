module labex1bh(a,b,c,d,f);
input a,b,c,d;
output f;
wire g,h,i,j,k;
assign g = (a&b);
assign h = (g|c);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
assign i = ~h;
assign j = (i&d);
assign k = (h|d);
assign f = (j&k);
endmodule
