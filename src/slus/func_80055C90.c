#include "types.h"

extern u8 D_8009A0A0[];
extern void func_800171E8(u8* obj, s32 state);

void func_80055C90(u8* obj) {
    u8* g = D_8009A0A0;

    *(s32*)(g + 8) = *(s32*)(obj + 8);
    if (g[0xF5] == 3) {
        func_800171E8(obj, 2);
        *(s32*)(obj + 0x7C) = 40;
        obj[5]++;
    }
}
