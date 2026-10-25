#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FBA4C_ovl56(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    p->unkA0 = 1;
    *(s32*)&p->pad58[4] -= 0x3BBBB;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        p->unk5E = 0x190;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        func_8002385C(0x6A, 0xFF, 0);
        arg0->pad2[0] = 3;
        arg0->unk1++;
    }
}
