#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A1F8[];
extern s32 D_800FB694_ovl00;

void func_800F84F4_ovl00(u8* obj) {
    u8* g;

    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 0);
        g = D_8009A1F8;
        g[0x98] = 0;
        g[0xA6] = 0;
        obj[0x90] = 1;
        *(s32*)(obj + 0x24) = 0xFFFF0000;
        *(s32*)(obj + 0x2C) = -0x600;
        D_800FB694_ovl00 = 30000;
        obj[6]++;
    }
}
