#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* os_detec();
const char* aarch_detec();

int main() {
    const char* os = os_detec();
    const char* arch = aarch_detec();

    printf("%s %s\n", os, arch);

    if (strcmp(os, "Linux") == 0 && strcmp(arch, "x86_64") == 0) {
        system("nasm -f elf64 x86-64/linux/linput_x86-64.asm -o asm_obj_f/linux_input_x86_64.o");
    } else if (strcmp(os, "Linux") == 0 && strcmp(arch, "x86") == 0) {
        system("nasm -f elf32 x86/linux/linput_x86.asm -o asm_obj_f/linux_input_x86.o");
    } else if (strcmp(os, "Windows") == 0 && strcmp(arch, "x86_64") == 0) {
        system("nasm -f win64 x86-64/windows/winput_x86-64.asm -o asm_obj_f/win_input_x86_64.obj");
    } else if (strcmp(os, "Windows") == 0 && strcmp(arch, "x86") == 0) {
        system("nasm -f win32 x86/windows/winput_x86.asm -o asm_obj_f/win_input_x86.obj");
    } else {
        printf("ERROR: No nasm assembler compilation support to %s %s\n", os, arch);
    }

    return 0;
}
