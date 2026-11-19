#include "types.h"

extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FDFA0_ovl32(u8* arg0) {
    s32 t;
    s32 v;

    t = 0x10;
    arg0[0x36] = t;
    t = -1;
    arg0[0x37] = t;
    t = arg0[4];
    v = 0x11;
    arg0[0] = v;
    v = 0x62B1;
    *(s16*)(arg0 + 0x34) = v;
    v = 1;
    arg0[3] = v;
    v = 0x140;
    *(s16*)(arg0 + 0x1E) = v;
    *(s16*)(arg0 + 0x26) = v;
    v = 0xF0;
    *(s16*)(arg0 + 0x2A) = v;
    *(s16*)(arg0 + 0x32) = v;
    *(s16*)(arg0 + 0xA) = 0;
    *(s16*)(arg0 + 0xE) = 0;
    *(s16*)(arg0 + 0x16) = 0;
    *(s16*)(arg0 + 0x1A) = 0;
    *(s16*)(arg0 + 0x22) = 0;
    *(s16*)(arg0 + 0x2E) = 0;
    t++;
    arg0[4] = t;
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
}
