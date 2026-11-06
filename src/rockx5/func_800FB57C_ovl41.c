#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800FB57C_ovl41(UnkObj* e) {
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
    *(s32*)(p + 8) += 0xFFF4CCCD;
    if (++e->unk4 >= 10) {
        *(s16*)(p + 0xA) = 0x1F0;
        p[0x4C] = 1;
        func_8002385C(0xB, 0xFF, 0);
        e->unk1++;
    }
}
