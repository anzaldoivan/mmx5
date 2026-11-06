#include "types.h"

extern void func_8002A080(u8* arg0);
extern void func_800F0260_ovl04(void);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800EF9D8_ovl04(u8* arg0) {
    u8* q;
    u8* p;

    q = D_8009A1F8;
    *(s32*)(q + 0x14) = *(s32*)(q + 0x8);
    *(s32*)(q + 0x18) = *(s32*)(q + 0xC);
    if (*(s16*)(q + 0x1C) < *(s16*)(q + 0xA)) {
        *(s16*)(q + 0xA) = *(s16*)(q + 0x1C);
    }
    if (*(s16*)(q + 0x1E) >= *(s16*)(q + 0xA)) {
        *(s16*)(q + 0xA) = *(s16*)(q + 0x1E);
    }
    if (*(s16*)(q + 0x20) < *(s16*)(q + 0xE)) {
        *(s16*)(q + 0xE) = *(s16*)(q + 0x20);
    }
    if (*(s16*)(q + 0x22) >= *(s16*)(q + 0xE)) {
        *(s16*)(q + 0xE) = *(s16*)(q + 0x22);
    }
    func_8002A080(q);
    func_800F0260_ovl04();
    p = D_800D1C00;
    if (p[0x26] & 4) {
        p[0x1D] = 3;
        arg0[6]++;
    }
}
