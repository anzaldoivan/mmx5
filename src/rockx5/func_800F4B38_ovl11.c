#include "types.h"

extern u8 D_8009A1F8[];
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, void*);

void func_800F4B38_ovl11(u8* a0) {
    u8* p = D_8009A1F8;

    if (*(s16*)(p + 0xE) == 0x2FB) {
        *(s16*)(p + 0x2E) = 0x80;
        a0[0x83] = 0x1E;
        func_8001296C(6);
        func_80016490(5, 0x1A, a0);
        a0[6] = 2;
    }
}
