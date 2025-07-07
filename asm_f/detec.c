#include <stdio.h>

const char* os_detec() {
#if defined(_WIN32) || defined(_WIN64)
    return "Windows";
#elif defined(__linux__)
    return "Linux";
#elif defined(__APPLE__) && defined(__MACH__)
    return "macOS";
#elif defined(__unix__)
    return "Unix";
#else
    return "Unkown";
#endif
}

const char* aarch_detec() {
#if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
#elif defined(__i386__) || defined(_M_IX86)
    return "x86";
#else
    return "Unkown";
#endif
}


