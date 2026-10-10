#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FAFC4_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    *(s32*)&p->pad58[4] -= 0x55555;
    p->unkA0 = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 60) {
        p->unk5E = 0;
        p->unkA0 = 1;
        func_8002385C(0x74, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
