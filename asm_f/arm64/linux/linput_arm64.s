
.global input_key

.text
input_key:
    ldrb w1, [x0]         // keys[0] - KEY_A
    cbz w1, check_d
    mov w0, #65           // KEY_A
    ret

check_d:
    ldrb w1, [x0, #1]     // keys[1] - KEY_D
    cbz w1, check_space
    mov w0, #68           // KEY_D
    ret

check_space:
    ldrb w1, [x0, #2]     // keys[2] - KEY_SPACE
    cbz w1, check_left
    mov w0, #32           // KEY_SPACE
    ret

check_left:
    ldrb w1, [x0, #3]     // keys[3] - KEY_LEFT
    cbz w1, check_right
    mov w0, #263          // KEY_LEFT
    ret

check_right:
    ldrb w1, [x0, #4]     // keys[4] - KEY_RIGHT
    cbz w1, no_key
    mov w0, #262          // KEY_RIGHT
    ret

no_key:
    mov w0, #0
    ret
