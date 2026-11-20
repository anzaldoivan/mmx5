#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void memcpy(void* dst, void* src, s32 n);
extern u8 D_8009A197;
extern u8 D_8009A790[];
extern u8 D_800C9310;

void func_8002C338(s32 idx, void* src, s32 count) {
    s32 off = idx << 5;
    s32 size = count << 5;

    memcpy(D_1F800028 + off, src, size);
    if (D_8009A197) {
        // !FAKE: register pin keeps the base in v0
        register u8* base asm("$2") = D_8009A790;
        memcpy(base + off, src, size);
        D_800C9310 = 2;
    } else {
        D_800C9310 |= 1;
    }
}
