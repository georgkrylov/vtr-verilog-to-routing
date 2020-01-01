module top_module
(
    
    input [1:0] a1,a2,b1,b2,a3,b3,a4,b4,a5,b5,a6,b6,
    output [3:0] c1,c2,c3,c4,c5,c6
   
);
  assign c1 = a1*b1;
  assign c2 = a2*b2;
  assign c3 = a3*b3;
  assign c4 = a4*b4;
  assign c5 = a5*b5;
  assign c6 = a6*b6;

endmodule
