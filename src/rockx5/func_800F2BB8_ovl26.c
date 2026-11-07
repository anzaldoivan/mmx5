#include "types.h"
#include "addr.h"

extern void func_80024548(s32);
extern void func_8003D29C(s32, s32);
extern void func_80044DD0(s32);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800F2BB8_ovl26(u8* obj) {
    s16 t;
    s32 k;
    u8* g;
    u8* h;

    t = --*(s16*)(obj + 0x7C);
    if (t == 0) {
        func_8003D29C(0x14, 0x40);
    } else if (t == 0x90) {
        h = D_8009A1F8;
        *(s16*)(h + 0x26) = *(s16*)(h + 0x24) -= 0x10;
    }
    if (**(s8**)(D_1F80004C.bytes + 0x84) == 0) {
        g = D_800D1C00;
        k = 1;
        g[0x24] = k;
        k = 0x40;
        g[0xA2] = k;
        g[0x25] = 0;
        *(u8**)(g + 0x20) = obj;
        if ((s8)g[0xC] == 0xC) {
            func_80024548(-1);
        } else {
            func_80024548(1);
        }
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        func_80044DD0(0);
        obj[6]++;
    }
}
