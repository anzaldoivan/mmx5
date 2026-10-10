#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FA7A8_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    *(s32*)&p->pad60[0] += 0x40000;
    p->unkA0 = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        func_8002385C(0x60, 0xFF, 0);
        p->unk62 = 0x178;
        p->unkA0 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
