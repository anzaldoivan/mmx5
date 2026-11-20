#include "types.h"

extern u8 D_8009A1F8[];
extern void func_80013288(s32);

void func_800FA0E4_ovl51(UnkObj* obj) {
    u8* p = D_8009A1F8;

    p[0x3] = 0;
    p[0x57] = 0;
    p[0xAB] = 0;
    func_80013288(8);
    obj->unk1++;
}
