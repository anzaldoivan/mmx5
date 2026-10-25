/* Shared body (DK-5), from the banked draft of func_800F5B44_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

extern ObjF5B44* DEDUP_CALLEE();

void DEDUP_NAME(ObjF5B44* arg0, u8 arg1) {
    ObjF5B44* obj = DEDUP_CALLEE();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x26;
        obj->unk7C = arg0;
        obj->unk15 = arg0->unk15;
        obj->unk2 = arg1;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
        if (arg1 == 0) {
            if (arg0->unk15 == 0) {
                obj->unkA = arg0->unkA - 0x2B;
            } else {
                obj->unkA = arg0->unkA + 0x2B;
            }
            obj->unkE = arg0->unkE;
        } else {
            if (arg0->unk15 == 0) {
                obj->unkA = arg0->unkA - 0x2C;
            } else {
                obj->unkA = arg0->unkA + 0x2C;
            }
            obj->unkE = arg0->unkE + 0x19;
        }
        obj->unk8 = 0;
        obj->unkC = 0;
    }
}
