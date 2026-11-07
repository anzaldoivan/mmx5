#include "types.h"

extern u8 D_8009A0A0[];
extern void* D_800F4894_ovl02[];
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800F2FC4_ovl02(u8* a0) {
    u8* p = D_8009A0A0;
    s8 s;

    if (p[0xF7] == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        ((void (*)(u8*))D_800F4894_ovl02[((s8*)a0)[5]])(a0);
    }
    if (((s8*)p)[2] != 0 || p[0xFA] != 3) {
        func_800317B8(a0);
    }
    s = ((s8*)a0)[5];
    if (s != 0) {
        *(s32*)(a0 + 0x94) = s;
    }
    if (func_8002D938(a0, 0x20, 0x20) == 1) {
        a0[4]++;
    }
}
