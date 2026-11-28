#include "types.h"

void func_80013388(u32* src, u32* dst, s32 n) {
    do {
        *dst++ = *src++;
    } while (--n);
}
