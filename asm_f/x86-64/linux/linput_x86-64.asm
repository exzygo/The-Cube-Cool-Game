global input_key

section .text
input_key:
    cmp byte [rdi], 0
    je check_D
    mov eax, 65          ; KEY_A
    ret

check_D:
    cmp byte [rdi+1], 0
    je check_SPACE
    mov eax, 68          ; KEY_D
    ret

check_SPACE:
    cmp byte [rdi+2], 0
    je check_LEFT
    mov eax, 32          ; KEY_SPACE
    ret

check_LEFT:
    cmp byte [rdi+3], 0
    je check_RIGHT
    mov eax, 263         ; KEY_LEFT
    ret

check_RIGHT:
    cmp byte [rdi+4], 0
    je none
    mov eax, 262         ; KEY_RIGHT
    ret

none:
    xor eax, eax
    ret
