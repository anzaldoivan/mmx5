#include "types.h"

extern u8 D_8009A1F8[];

extern void func_8002385C(s32, s32, s32);

void func_800FAA4C_ovl46(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8;
    p[0xF4] = 1;
    p[0x4C] = 1;
    *(s32*)(p + 8) += -0xCCCCC;
    if (*(s32*)(p + 8) <= 0x2C00000) {
        *(s32*)(p + 8) = 0x2C00000;
        func_8002385C(0x1F, 0xFF, 0);
        e->unk4 = 0;
        e->unk1++;
    }
}
