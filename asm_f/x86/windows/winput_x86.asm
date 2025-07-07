global _input_key

section .text
_input_key:
    push ebp
    mov ebp, esp
    mov esi, [ebp+8]

    cmp byte [esi], 0
    je .check_D
    mov eax, 65
    jmp .done

.check_D:
    cmp byte [esi+1], 0
    je .check_SPACE
    mov eax, 68
    jmp .done

.check_SPACE:
    cmp byte [esi+2], 0
    je .check_LEFT
    mov eax, 32
    jmp .done

.check_LEFT:
    cmp byte [esi+3], 0
    je .check_RIGHT
    mov eax, 263
    jmp .done

.check_RIGHT:
    cmp byte [esi+4], 0
    je .none
    mov eax, 262
    jmp .done

.none:
    xor eax, eax

.done:
    pop ebp
    ret

