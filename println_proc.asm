; ============================================================================
; print_int — call with the integer value already in EAX.
; Prints the signed decimal value followed by a newline, via write(2).
; FASM ELF 32-bit Linux syntax.
; ============================================================================
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

    MOV EDI, int_buf + 11      ; work backwards from end of buffer
    MOV ESI, 0                 ; digit count
    MOV ECX, 10

.convert_loop:
    XOR EDX, EDX
    MOV EAX, EBX
    DIV ECX                     ; EAX = EBX/10, EDX = EBX%10
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

    MOV byte [int_buf + 11], 10 ; newline right after the last digit position
    INC ESI

    MOV EAX, 4                  ; sys_write
    MOV EBX, 1                  ; stdout
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
