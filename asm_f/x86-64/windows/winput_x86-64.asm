global input_key

section .text
input_key:
    cmp byte [rcx], 0
    je check_D
    mov eax, 65
    ret

check_D:
    cmp byte [rcx+1], 0
    je check_SPACE
    mov eax, 68
    ret

check_SPACE:
    cmp byte [rcx+2], 0
    je check_LEFT
    mov eax, 32
    ret

check_LEFT:
    cmp byte [rcx+3], 0
    je check_RIGHT
    mov eax, 263
    ret

check_RIGHT:
    cmp byte [rcx+4], 0
    je none
    mov eax, 262
    ret

none:
    xor eax, eax
    ret
