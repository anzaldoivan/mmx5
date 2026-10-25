#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];

void func_800FAD30_ovl50(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        p = D_8009A1F8;
        p[3] = 0;
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0;
        p[0xA0] = 1;
        p[0x57] = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
        func_80016490(2, 0x4D, 0);
    }
}
