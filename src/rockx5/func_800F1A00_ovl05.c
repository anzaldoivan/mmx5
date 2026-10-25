#include "types.h"

extern void func_800171E8(Obj1A00*, s32);

void func_800F1A00_ovl05(Obj1A00* obj) {
    u8 t = obj->unk45;

    if (obj->unk45 == 2) {
        s8 s = obj->unk2;
        if (s >= 0) {
            if (s < 3) {
                func_800171E8(obj, 0xE);
                obj->unk88 = 0xE;
            } else if (s < 6) {
                func_800171E8(obj, 1);
                obj->unk88 = 0xB4;
            }
        }
        obj->unk6++;
        return;
    }
    obj->unk8D = -t;
    obj->unk8F = t;
}
