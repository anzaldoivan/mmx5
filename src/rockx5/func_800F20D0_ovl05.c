#include "types.h"

extern void func_800171E8(Obj1D68*, s32);

void func_800F20D0_ovl05(Obj1D68* obj) {
    u8 t = obj->unk45;

    if (obj->unk45 == 2) {
        s8 s = obj->unk2;
        if (s >= 0) {
            if (s < 3) {
                func_800171E8(obj, 0x14);
                obj->unk88 = 0xE;
            } else if (s < 6) {
                func_800171E8(obj, 7);
                obj->unk88 = 0xB4;
            }
        }
        obj->unk6++;
        return;
    }
    obj->unk8C = 0;
    obj->unk8E = t;
}
