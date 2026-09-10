format ELF executable 3
entry start

segment readable writable

segment readable executable
start:
	CALL func_main
	MOV EAX, 1
	XOR EBX, EBX
	INT 0x80

	; line 1: function func()
func_func:
	PUSH EBP
	MOV EBP,ESP
	SUB ESP,4
	; line 3: if (n==0)
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 0
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETE AL
	PUSH EAX
	pop eax
	cmp eax,0
	je L0
	; line 3: return 0
	MOV EAX, 0
	PUSH EAX
	POP EAX
	MOV ESP,EBP
	POP EBP
	RET 4
L0:
	; line 4: i=n
	MOV EAX, [EBP+8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
	; line 5: return func(n-1)+i
	; line 5: call func(n-1)
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 1
	PUSH EAX
	POP EBX
	POP EAX
	SUB EAX, EBX
	PUSH EAX
	CALL func_func
	PUSH EAX
	MOV EAX, [EBP-4]
	PUSH EAX
	POP EBX
	POP EAX
	ADD EAX, EBX
	PUSH EAX
	POP EAX
	MOV ESP,EBP
	POP EBP
	RET 4
	MOV ESP, EBP
	POP EBP
	RET 4
	; line 8: function func2()
func_func2:
	PUSH EBP
	MOV EBP,ESP
	SUB ESP,4
	; line 10: if (n==0)
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 0
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETE AL
	PUSH EAX
	pop eax
	cmp eax,0
	je L1
	; line 10: return 0
	MOV EAX, 0
	PUSH EAX
	POP EAX
	MOV ESP,EBP
	POP EBP
	RET 4
L1:
	; line 11: i=n
	MOV EAX, [EBP+8]
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
	; line 12: return func(n-1)+i
	; line 12: call func(n-1)
	MOV EAX, [EBP+8]
	PUSH EAX
	MOV EAX, 1
	PUSH EAX
	POP EBX
	POP EAX
	SUB EAX, EBX
	PUSH EAX
	CALL func_func
	PUSH EAX
	MOV EAX, [EBP-4]
	PUSH EAX
	POP EBX
	POP EAX
	ADD EAX, EBX
	PUSH EAX
	POP EAX
	MOV ESP,EBP
	POP EBP
	RET 4
	MOV ESP, EBP
	POP EBP
	RET 4
	; line 15: function main()
func_main:
	PUSH EBP
	MOV EBP,ESP
	SUB ESP,4
	; line 17: a=func(7)
	; line 17: call func(7)
	MOV EAX, 7
	PUSH EAX
	CALL func_func
	PUSH EAX
	POP EAX
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
	; line 18: println(a)
	MOV EAX, [EBP-4]
	CALL print_int
	; line 19: return 0
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

segment readable writable
int_buf:   rb 16
neg_flag:  dd 0
