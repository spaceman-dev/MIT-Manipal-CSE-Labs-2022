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
	LDR R0, =SRC
	LDR R1, =DST
	LDR R2, [R0]
	MOV R3, #8
	MOV R4, #0XF
	MOV R5, #0X50
UP	MOV R6, R2
	AND R6, R4
	ORR R6, R6, R5
	STR R6, [R1], #4
	SUBS R3, #1
	BNE UP
STOP
	B STOP
SRC DCD 0X00000009
	AREA mydata, DATA, READWRITE
DST DCD 0
	END.