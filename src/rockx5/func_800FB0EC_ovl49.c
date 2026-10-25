#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002385C(s32, s32, s32);

void func_800FB0EC_ovl49(UnkObj* arg0) {
    D_8009A1F8_t* p;

    if (arg0->unk4 == 0) {
        func_8002385C(0x2F, 0xFF, 0);
        p = &D_8009A1F8;
        *(s32*)(p->pad0 + 8) = 0x2000000;
        *(s32*)p->padC = 0x1000000;
        p->pad49[0x4C - 0x49] = 1;
        p->pad0[3] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
