   .syntax   unified
    .cpu     cortex-m4
    .text
	
	.global   Log2Phys
    .thumb_func
    .align
Log2Phys:				//r0 = lba r1 = heads r2 = sectors r3 = *phy
	PUSH {R4-R8}
						//compute cylinder R4
	MUL R4, R1, R2		//heads times sectors stored in R4
	UDIV R4, R0, R4 	//r4 = lba/heads*sectors
	STRH R4, [R3]
	
						//compute head R5
	UDIV R5, R0, R2 	//R5 holds lba/sectors
	UDIV R6, R5, R1
	MLS R6, R1, R6, R5	//R0 = R0-R2(R0*R2)
	ADD R3, R3, 2
	STRB R6, [R3]
	
						//compute sector
	UDIV R7, R0, R2 	//R5 = r0(dividend)/r2(divisor)
	MLS R8, R2, R7, R0	//R6 = R5(quotient)*r2(divisor)
	ADD R8, R8, 1
	ADD R3, R3, 1
	STRB R8, [R3]
	POP {R4-R8}
	//structures 
	
.end
	