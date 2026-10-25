/* Shared body (DK-5), from the banked draft of func_800F09D8_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(Obj09D8*, s32);

void DEDUP_NAME(Obj09D8* obj) {
    if (obj->unk70 & 8) {
        if (obj->unk24 != 0) {
            func_80016490(2, 0x42, obj);
        }
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
    }
    if (obj->unk46 == 0) {
        func_800171E8(obj, 7);
        func_80016490(2, 0x3D, obj);
        obj->unk6++;
    }
}
