#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80101B10_ovl07[];

void func_800FCAD8_ovl07(ObjCAD8* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    ObjCAD8* obj = func_8002D1A4();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0xC;
        obj->unk7C = arg0;
        obj->unk2 = arg3;
        obj->unkA = arg1;
        obj->unkE = arg2;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = D_80101B10_ovl07;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
        obj->unk88 = arg4;
    }
}

// spawned child copies the parent's state, keeps the parent at 0x50

void func_800FCB98_ovl07(ObjFAF38* arg0, s16 arg1, s16 arg2, u8 arg3) {
    ObjFAF38* obj = func_8002D27C();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x1E;
        obj->unk2 = arg3;
        obj->unk40 = arg0->unk40;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk14 = arg0->unk14;
        obj->unkA = arg1;
        obj->unk8 = 0;
        obj->unkE = arg2;
        obj->unkC = 0;
        *(ObjFAF38**)&obj->pad44[0xC] = arg0; /* 0x50: the parent */
    }
}

extern s32 D_80093DD0[];
extern s32 D_80093DD8;

void func_800FCC54_ovl07(void) {
    if (D_800D1C0C.s == 12) {
        D_80093DD8 = 0x9000C000;
        return;
    }
    D_80093DD0[0] = 0xF0;
    D_80093DD0[2] = 0x40FF;
    D_80093DD0[1] = 0;
    D_80093DD0[3] = 0xA0004000;
    D_80093DD0[4] = 0x40000000;
}
