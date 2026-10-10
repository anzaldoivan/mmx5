#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FAC30_ovl56(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    p->unkA0 = 1;
    *(s32*)p->pad60 += 0x22222;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        *(s32*)p->pad60 = 0x800000;
        func_8002385C(0x5E, 0xFF, 0);
        arg0->unk1++;
    }
}
