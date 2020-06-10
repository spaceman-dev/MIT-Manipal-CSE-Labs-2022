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
	LDR R1, =Result
	LDR R3, [R0]
	LDR R4, =1
UP	MUL R4, R3
	SUBS R3, #1
	BNE UP
	STR R4, [R1]
HERE
	B HERE
Input DCD 5
	AREA mydata, DATA, READWRITE
Result DCD 0
	END