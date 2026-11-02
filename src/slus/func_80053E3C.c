#include "types.h"

extern void func_800545DC(s32);
extern void func_80016490(s32, s32, void*);
extern u8 D_8009A0A0[];
extern Gm1C00 D_800D1C00;

void func_80053E3C(u8* obj, u8 arg1, u8 arg2) {
    u8* b;
    Gm1C00* c;
    u8 hi;
    s8 i;
    u8* p;
    s8 t;
    u8 v;

    hi = D_8009A0A0[0x5C] & 0x80;
    if ((D_8009A0A0[0x5C] & 0x7F) <
        (s8)D_800D1C00.lim[*(s8*)(D_8009A0A0 + 2)]) {
        func_800545DC(1);
        obj[0x83] = arg1;
        obj[0x84] = 2;
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[0] |= 8;
    } else {
        obj[4] = 3;
    }
    b = D_8009A0A0;
    c = &D_800D1C00;
    v = c->lim[*(s8*)(b + 2)];
    if (!((b[0x5C] & 0x7F) < (s8)v)) {
        b[0x5C] = hi | v;
    }
    *(u16*)(b + 0xA8) += arg1 * 6;
    if (*(s16*)(b + 0x148) < *(s16*)(b + 0xA8)) {
        *(u16*)(b + 0xA8) = *(u16*)(b + 0x148);
    }
    for (i = 0; i < 2; i++) {
        p = c->cnt + i;
        if (*(volatile u16*)&c->flags &
            (0x1000 << i)) { // !FAKE: volatile keeps the per-pass reload
            t = *p & 0x7F;
            if (t < 0x20) {
                t += arg2 * 2;
                if (t >= 0x20) {
                    t = 0x20;
                    func_80016490(0, 0x18, 0);
                } else {
                    func_80016490(0, 0x17, 0);
                }
                *p = t | 0x80;
                break;
            }
        }
    }
}
