#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 func_80044DE0();

void func_800F7858_ovl03(Ent8EF0* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.t.unk26 = obj->unk94;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            play_sound(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.t.unk48 = 8;
    func_8003D2C4();
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    obj->unk5 = 4;
    obj->unk6 = 0;
}
