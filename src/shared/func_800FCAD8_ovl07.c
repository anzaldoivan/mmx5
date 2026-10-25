/* Shared body (DK-5), from the banked draft of func_800FCAD8_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern ObjCAD8* DEDUP_CALLEE();
extern u8 D_80101B10_ovl07[];

void DEDUP_NAME(ObjCAD8* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    ObjCAD8* obj = DEDUP_CALLEE();

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
