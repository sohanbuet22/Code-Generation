format ELF executable 3
entry start

segment readable writable
x dd 0
i dd 0
j dd 0
k dd 0
ll dd 0

segment readable executable
start:
	CALL main_logic
	MOV EAX, 1
	XOR EBX, EBX
	INT 0x80

main_logic:
	MOV EAX, 5
	PUSH EAX
	POP EAX
	mov [x], EAX
	; line 4: println(x)
	MOV EAX, [x]
	CALL print_int
	; line 7: for-loop init
	; line 7: i=0
	MOV EAX, 0
	PUSH EAX
	POP EAX
	MOV [i], EAX
	PUSH EAX
	POP EAX
L0:
	; line 7: for-loop condition
	MOV EAX, [i]
	PUSH EAX
	MOV EAX, 6
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETL AL
	PUSH EAX
	pop eax
	cmp eax, 0
	je L1
	; line 8: println(i)
	MOV EAX, [i]
	CALL print_int
	; line 7: for-loop update
	MOV EAX, [i]
	PUSH EAX
	INC EAX
	MOV [i], EAX
	pop eax
	jmp L0
L1:
	; line 11: k=4
	MOV EAX, 4
	PUSH EAX
	POP EAX
	MOV [k], EAX
	PUSH EAX
	POP EAX
	; line 12: ll=6
	MOV EAX, 6
	PUSH EAX
	POP EAX
	MOV [ll], EAX
	PUSH EAX
	POP EAX
L2:
	; line 13: while (k>0)
	MOV EAX, [k]
	PUSH EAX
	MOV EAX, 0
	PUSH EAX
	POP EBX
	POP EAX
	CMP EAX, EBX
	MOV EAX, 0
	SETG AL
	PUSH EAX
	pop eax
	cmp eax,0
	je L3
	; line 14: ll=ll+3
	MOV EAX, [ll]
	PUSH EAX
	MOV EAX, 3
	PUSH EAX
	POP EBX
	POP EAX
	ADD EAX, EBX
	PUSH EAX
	POP EAX
	MOV [ll], EAX
	PUSH EAX
	POP EAX
	MOV EAX, [k]
	PUSH EAX
	DEC EAX
	MOV [k], EAX
	POP EAX
	jmp L2
L3:
	; line 18: println(ll)
	MOV EAX, [ll]
	CALL print_int
	; line 19: println(k)
	MOV EAX, [k]
	CALL print_int
	; line 21: k=4
	MOV EAX, 4
	PUSH EAX
	POP EAX
	MOV [k], EAX
	PUSH EAX
	POP EAX
	; line 22: ll=6
	MOV EAX, 6
	PUSH EAX
	POP EAX
	MOV [ll], EAX
	PUSH EAX
	POP EAX
L4:
	; line 24: while (k--)
	MOV EAX, [k]
	PUSH EAX
	DEC EAX
	MOV [k], EAX
	pop eax
	cmp eax,0
	je L5
	; line 25: ll=ll+3
	MOV EAX, [ll]
	PUSH EAX
	MOV EAX, 3
	PUSH EAX
	POP EBX
	POP EAX
	ADD EAX, EBX
	PUSH EAX
	POP EAX
	MOV [ll], EAX
	PUSH EAX
	POP EAX
	jmp L4
L5:
	; line 28: println(ll)
	MOV EAX, [ll]
	CALL print_int
	; line 29: println(k)
	MOV EAX, [k]
	CALL print_int
	MOV EAX, 0
	PUSH EAX
	POP EAX
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
