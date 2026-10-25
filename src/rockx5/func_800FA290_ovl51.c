#include "types.h"

extern u8 D_8009A1F8[];
extern void func_8002385C(s32, s32, s32);

void func_800FA290_ovl51(UnkObj* arg0) {
    u8* p = D_8009A1F8;

    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += -0xB3333;
    arg0->unk4++;
    if (arg0->unk4 >= 11) {
        *(s16*)(p + 0x5E) = 0xD0;
        func_8002385C(0x44, 0xFF, 0);
        arg0->unk1++;
    }
}
