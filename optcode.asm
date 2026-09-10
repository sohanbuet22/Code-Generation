format ELF executable 3
entry main
segment readable writeable
segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 4
	SUB ESP, 4
	SUB ESP, 4
.L1:
	MOV EAX, 3       ; Line 5
	MOV [EBP-4], EAX
.L2:
	MOV EAX, 8       ; Line 6
	MOV [EBP-8], EAX
.L3:
	MOV EAX, 6       ; Line 7
	MOV [EBP-12], EAX
.L4:
	MOV EAX, 3       ; Line 10
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 10
	CMP EAX, EDX
	JE .L5
	JMP .L7
.L5:
	MOV EAX, [EBP-8]       ; Line 11
	CALL print_number
.L6:
.L7:
	MOV EAX, 8       ; Line 14
	MOV EDX, EAX
	MOV EAX, [EBP-8]       ; Line 14
	CMP EAX, EDX
	JL .L8
	JMP .L10
.L8:
	MOV EAX, [EBP-4]       ; Line 15
	CALL print_number
.L9:
	JMP .L12
.L10:
	MOV EAX, [EBP-12]       ; Line 18
	CALL print_number
.L11:
.L12:
	MOV EAX, 6       ; Line 21
	MOV EDX, EAX
	MOV EAX, [EBP-12]       ; Line 21
	CMP EAX, EDX
	JNE .L13
	JMP .L15
.L13:
	MOV EAX, [EBP-12]       ; Line 22
	CALL print_number
.L14:
	JMP .L24
.L15:
	MOV EAX, 8       ; Line 24
	MOV EDX, EAX
	MOV EAX, [EBP-8]       ; Line 24
	CMP EAX, EDX
	JG .L16
	JMP .L18
.L16:
	MOV EAX, [EBP-8]       ; Line 25
	CALL print_number
.L17:
	JMP .L24
.L18:
	MOV EAX, 5       ; Line 27
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 27
	CMP EAX, EDX
	JL .L19
	JMP .L21
.L19:
	MOV EAX, [EBP-4]       ; Line 28
	CALL print_number
.L20:
	JMP .L24
.L21:
	MOV EAX, 0       ; Line 31
	MOV [EBP-12], EAX
.L22:
	MOV EAX, [EBP-12]       ; Line 32
	CALL print_number
.L23:
.L24:
	MOV EAX, 0       ; Line 36
	JMP .L26
.L25:
.L26:
	ADD ESP, 12
	POP EBP
	MOV EAX,1
	XOR EBX, EBX
	INT 0x80
	POP EBP
	RET
;-------------------------------
;         print library         
;-------------------------------
;-------------------------------
