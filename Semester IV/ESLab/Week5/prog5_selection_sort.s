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
	LDR R0, =List
	LDR R2, =Result
	MOV R3, #5
UP	LDR R1, [R0], #4
	STR R1, [R2], #4
	SUBS R3, #1
	BNE UP
	LDR R2, =Result
	LDR R4, [R2]
	MOV R5, #1
	MOV R6, #4
ABOVE CMP R5, R6
	BHI LAST
	MOV R7, R2
	MOV R8, #5
	ADD R9, R5, #1
	MOV R3, R7
L3	CMP R9, R8
	BHI L2
	LDR R10, [R7]
	ADD R3, R3, #4
	LDR R11, [R3]
	CMP R10, R11
	MOVCS R7, R3
	ADD R9, #1
	B L3
L2	LDR R0, [R3]
	LDR R1, [R2]
	STR R0, [R2]
	STR R1, [R7]
	ADD R2, #4
	ADD R5, #4
	B ABOVE
LAST
	B LAST
List DCD 0X10, 0X5, 0X33, 0X24, 0X56, 0X77, 0X21, 0X4, 0X87, 0X1
	AREA mydata, DATA, READWRITE
Result DCW 0,0,0,0,0,0,0,0,0,0
	END