#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_80091C44;

void func_800FB450_ovl41(UnkObj* e) {
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
    if (D_80091C44 == 0) {
        p[0xA0] = 1;
        *(s32*)(p + 0x5C) += -0xCCCCC;
        if (++e->unk4 >= 0xA) {
            *(s16*)(p + 0x5E) = 0x1E0;
            e->unk1++;
        }
    }
}
