#include "types.h"
#include "mmx5/globals.h"

extern D_8009A1F8_t D_8009A1F8;

void func_800FA88C_ovl58(UnkObj* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8;

    p->pad49[0x4C - 0x49] = 1;
    *(s32*)&p->pad0[8] += 0x160000;
    arg0->unk4++;
    if (arg0->unk4 >= 16) {
        func_8002385C(0x61, 0xFF, 0);
        p->unkA = 0x160;
        p->pad49[0x4C - 0x49] = 1;
        arg0->unk1++;
    }
}
