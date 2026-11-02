#include "types.h"

extern void func_8002D6FC(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_80076E70[];
extern s32 D_8009A420;

void func_80045BDC(u8* obj) {
    u8* p = D_8009A0A0;

    if (*(s8*)(p + 5) != 0x25) {
        func_8002D6FC(obj);
    }
    if (*(s8*)(obj + 4) == 0) {
        obj[4]++;
        obj[3] = 0;
        obj[0x64] = 1;
        *(u8**)(obj + 0x50) = D_80076E70;
        obj[0x15] = 0;
        obj[0x98] = 0;
        *(u32*)(obj + 0x8C) = 0;
        if (p[0x15] != 0) {
            *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) + 0x16;
        } else {
            *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) - 0x16;
        }
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
        return;
    }
    if (*(s8*)(p + 0x45) == 0) {
        func_8002D6FC(obj);
        return;
    }
    if (!(D_8009A420 & 3)) {
        obj[0x64]++;
    }
    if (*(s8*)(obj + 0x98) != 0) {
        obj[0x98] = 0;
        if (++*(u32*)(obj + 0x8C) >= 8) {
            func_8002D6FC(obj);
        }
    }
}
