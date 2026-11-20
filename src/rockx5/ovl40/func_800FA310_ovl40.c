#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A1F8[];
extern s32 D_800FA688_ovl40;

void func_800FA310_ovl40(Ovl45State* a0) {
    u8* p;

    if (a0->unk4 == 0) {
        func_8002385C(1, 0xFF, 0);
        a0->unk1++;
        p = D_8009A1F8;
        D_800FA688_ovl40 = 0x700000;
        a0->unk4 = 0x3C;
        p[0x3] = 0;
        *(s16*)(p + 0x62) = 0;
        *(s16*)(p + 0x5E) = 0x200;
        *(s32*)(p + 0x5C) += 0x700000;
        p[0xA0] = 1;
        p[0x57] = 1;
    }
}
