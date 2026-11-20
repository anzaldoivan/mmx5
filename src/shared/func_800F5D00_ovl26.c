/* Shared body (DK-5), from the banked draft of func_800F5D00_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F9654_ovl26[];

void DEDUP_NAME(Obj5D00* obj) {
    animate_object(obj);
    if (obj->unk7C[7] == 0) {
        set_animation(obj, 2);
        obj->unk5 = 1;
        obj->unk6 = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0x1000;
        obj->unk68 = D_800F9654_ovl26;
    }
}
