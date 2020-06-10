	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =Input
	LDR R1, =Position
	MOV R3, #10
	MOV R4, #76
	MOV R6, #1
	MOV R7, #0
LOOP LDR R5, [R0], #4
	ADD R7, #1
	CMP R4, R5
	BEQ UP
	SUBS R3, #1
	BNE LOOP
HERE
	B HERE
UP	STR R6, [R1], #4
	STR R7, [R1]
Input DCD 0, 1, 2, 3, 4, 76, 6, 7, 8, 9
	AREA mydata, DATA, READWRITE
Position DCD 3
	END
