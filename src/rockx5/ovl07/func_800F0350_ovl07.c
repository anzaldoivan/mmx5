#include "types.h"
#include "mmx5/globals.h"

extern void (*D_80100860_ovl07[])(u8*);

void func_800F0350_ovl07(u8* obj) {
    u8* g;

    if (*(s16*)(obj + 0xA) >= 0x1D51 || !((g = g_Player)[0x5C] & 0x7F)) {
        *(u16*)(obj + 0x8A) = 2;
        *(u16*)(obj + 0x8C) = 0;
    } else {
        *(u16*)(obj + 0x8A) = *(u16*)(g + 0x7C);
        *(u16*)(obj + 0x8C) = *(u16*)(g + 0x80);
    }
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    D_80100860_ovl07[((s8*)obj)[4]](obj);
    obj[0x71] = 0;
    obj[0x5C] &= 0x7F;
}
