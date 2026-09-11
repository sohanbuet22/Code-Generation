format ELF executable 3
entry start

segment readable writeable

segment readable executable
start:
	CALL func_main
	MOV EAX, 1
	XOR EBX, EBX
	INT 0x80

	; line 1: function main()
func_main:
	PUSH EBP
	MOV EBP,ESP
	SUB ESP,4
	SUB ESP,4
	SUB ESP,4
	; line 5: i=3
	MOV EAX, 3
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
	; line 6: j=8
	MOV EAX, 8
	PUSH EAX
	POP EAX
	MOV [EBP-8], EAX
	PUSH EAX
	POP EAX
	; line 7: k=6
	MOV EAX, 6
	PUSH EAX
	POP EAX
	MOV [EBP-12], EAX
	PUSH EAX
	POP EAX
	; line 10: if (i==3)
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 3
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETE AL
	PUSH EAX
	POP EAX
	CMP EAX, 0
	JE L0
	; line 11: println(j)
	MOV EAX, [EBP-8]
	CALL print_int
L0:
	; line 14: if (j<8) ... else ...
	MOV EAX, [EBP-8]
	PUSH EAX
	MOV EAX, 8
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETL AL
	PUSH EAX
	POP EAX
	CMP EAX, 0
	JE L1
	; line 15: println(i)
	MOV EAX, [EBP-4]
	CALL print_int
	JMP L2
L1:
	; line 18: println(k)
	MOV EAX, [EBP-12]
	CALL print_int
L2:
	; line 21: if (k!=6) ... else ...
	MOV EAX, [EBP-12]
	PUSH EAX
	MOV EAX, 6
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETNE AL
	PUSH EAX
	POP EAX
	CMP EAX, 0
	JE L3
	; line 22: println(k)
	MOV EAX, [EBP-12]
	CALL print_int
	JMP L4
L3:
	; line 24: if (j>8) ... else ...
	MOV EAX, [EBP-8]
	PUSH EAX
	MOV EAX, 8
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETG AL
	PUSH EAX
	POP EAX
	CMP EAX, 0
	JE L5
	; line 25: println(j)
	MOV EAX, [EBP-8]
	CALL print_int
	JMP L6
L5:
	; line 27: if (i<5) ... else ...
	MOV EAX, [EBP-4]
	PUSH EAX
	MOV EAX, 5
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETL AL
	PUSH EAX
	POP EAX
	CMP EAX, 0
	JE L7
	; line 28: println(i)
	MOV EAX, [EBP-4]
	CALL print_int
	JMP L8
L7:
	; line 31: k=0
	MOV EAX, 0
	PUSH EAX
	POP EAX
	MOV [EBP-12], EAX
	PUSH EAX
	POP EAX
	; line 32: println(k)
	MOV EAX, [EBP-12]
	CALL print_int
L8:
L6:
L4:
	; line 36: return 0
	MOV EAX, 0
	PUSH EAX
	POP EAX
	MOV ESP,EBP
	POP EBP
	RET
	MOV ESP, EBP
	POP EBP
	RET
print_int:
    PUSH EBP
    MOV EBP, ESP
    PUSH EBX
    PUSH ECX
    PUSH EDX
    PUSH EDI
    PUSH ESI

    MOV [neg_flag], dword 0
    MOV EBX, EAX
    TEST EBX, EBX
    JNS .positive
    MOV [neg_flag], dword 1
    NEG EBX
.positive:

    MOV EDI, int_buf + 11
    MOV ESI, 0
    MOV ECX, 10

.convert_loop:
    XOR EDX, EDX
    MOV EAX, EBX
    DIV ECX
    ADD EDX, '0'
    DEC EDI
    MOV [EDI], DL
    INC ESI
    MOV EBX, EAX
    TEST EBX, EBX
    JNZ .convert_loop

    CMP dword [neg_flag], 0
    JE .no_sign
    DEC EDI
    MOV byte [EDI], '-'
    INC ESI
.no_sign:

    MOV byte [int_buf + 11], 10
    INC ESI

    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, EDI
    MOV EDX, ESI
    INT 0x80

    POP ESI
    POP EDI
    POP EDX
    POP ECX
    POP EBX
    MOV ESP, EBP
    POP EBP
    RET

segment readable writeable
int_buf:   rb 16
neg_flag:  dd 0
