#include "types.h"

extern D_8009A1F8_8_t D_8009A1F8;
extern s32 D_800FA688_ovl40;
extern void func_8002385C(s32, s32, s32);

void func_800FA4D0_ovl40(Ovl45State* a0) {
    D_8009A1F8_8_t* p;
    D_8009A1F8_8_t* q;
    s32 v;

    a0->unk4--;
    p = &D_8009A1F8;
    ((s16*)&p->unk8)[1] = 0x220;
    v = D_800FA688_ovl40 - 0x1DC28;
    D_800FA688_ovl40 = v;
    if (a0->unk4 & 1) {
        p->unk8 -= v;
    } else {
        p->unk8 += v;
    }
    q = &D_8009A1F8;
    ((u8*)q)[0x4C] = 1;
    if (a0->unk4 == 0) {
        func_8002385C(3, 0xFF, 0);
        ((s16*)&q->unk8)[1] = 0x220;
        a0->unk1++;
    }
}
