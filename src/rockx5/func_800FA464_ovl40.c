#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_8_t D_8009A1F8;
extern s32 D_800FA688_ovl40;

void func_800FA464_ovl40(Ovl45State* a0) {
    D_8009A1F8_8_t* p;

    if (D_80091C44 == 0) {
        D_800FA688_ovl40 = 0x700000;
        a0->unk4 = 0x3C;
        p = &D_8009A1F8;
        ((s16*)&p->unk8)[1] = 0x220;
        ((u8*)p)[3] = 1;
        ((s16*)p)[7] = 0;
        ((u8*)p)[0x4C] = 1;
        p->unk8 += 0x700000;
        a0->unk1++;
    }
}
