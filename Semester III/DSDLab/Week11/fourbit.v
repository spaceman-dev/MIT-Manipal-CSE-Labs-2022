module fourbit(clock,qq);

input clock;
output [3:0]qq;

jkff st0(1,1,clock,qq[0]);
jkff st1(1,1,qq[0],qq[1]);
jkff st2(1,1,qq[1],qq[2]);
jkff st3(1,1,qq[2],qq[3]);

endmodule

module jkff(j,k,clk,q);

input clk,j,k;
output q;
reg q;

always@(negedge clk)
	
	begin
		casex({j,k})
			3'b1xx:q<=0;
			3'b001:q<=0;
			3'b010:q<=1;
			3'b011:q<=~q;
			3'b000:q<=q;
		endcase
	end
endmodule


