#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800FA890_ovl46(UnkObj* e) {
    u8* p;

    if (e->unk4 == 0) {
        func_8002385C(0x1E, 0xFF, 0);
        p = D_8009A1F8;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0x200;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        e->unk4 = 0;
        e->unk6 = 0x14;
        e->unk1++;
    }
}
