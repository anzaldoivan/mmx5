#include "types.h"

extern u8 D_800D1D10;
extern u8 D_8009A0A0[];
extern void func_80016D54(s32, s32);
extern void func_8003CEA4(u8* obj);
extern void func_8003C5D8(u8* obj);

void func_8003F35C(void) {
    u8* p = D_8009A0A0;

    if ((D_800D1D10 & 1) && *(s8*)(p + 0x93) == 0) {
        return;
    }
    if (!(*(u16*)(p + 0x7C) & 0x10)) {
        p[0x9B] = 0;
        p[0x9D] = 0;
    }
    if (!(*(u16*)(p + 0x7C) & 0x20)) {
        p[0x9C] = 0;
        p[0x9E] = 0;
    }
    if (!(*(s32*)(p + 0x9C) & 0xFFFF00)) {
        func_80016D54(1, 7);
        func_8003CEA4(p);
        p[0x9B] = 0;
        p[0x9C] = 0;
        p[0x9D] = 0;
        p[0x9E] = 0;
        func_8003C5D8(p);
    }
}
