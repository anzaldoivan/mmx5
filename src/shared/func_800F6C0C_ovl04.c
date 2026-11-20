/* Shared body (DK-5), from the banked draft of func_800F6C0C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80101CDC_ovl04[];
extern u8 D_80101CEC_ovl04[];

void DEDUP_NAME(Obj6C0C* obj) {
    if (obj->unk93 & 8) {
        obj->unk50 = D_80101CDC_ovl04;
        obj->unk68 = D_80101CEC_ovl04;
        obj->unk5 = 3;
        obj->unk6 = 0;
        set_animation(obj, 0xC);
        if (obj->unk91 != 0) {
            obj->unk20 = -0x20000;
            obj->unk15 = 0;
            obj->unkA -= 6;
        } else {
            obj->unk20 = 0x20000;
            obj->unk15 = 0x40;
            obj->unkA += 6;
        }
        obj->unk24 = 0;
        obj->unk67 = 0;
    }
    animate_object(obj);
    move_object(obj);
}
