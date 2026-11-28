#include "types.h"
#include "mmx5/globals.h"

extern s32 D_800E92F8;

void func_800FAE70_ovl58(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 >= 61) {
        D_8009A1F8.t.pad0[3] = 0;
        D_8009A1F8.t.unk57 = 0;
        *(s16*)&D_8009A1F8.t.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.t.unkB6 = 0x400;
        D_8009A1F8.t.unkF4 = 1;
        D_800E92F8 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
