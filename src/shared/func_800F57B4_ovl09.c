#include "types.h"
#include "mmx5/ovl09.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800FB65C_ovl09;
extern s32 func_80044DE0();

void func_800F57B4_ovl09(Ent57B4* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.t.unk26 = D_800FB660_ovl09.h;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            play_sound(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.t.unk48 = D_800FB65C_ovl09;
    func_8003D2C4();
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    obj->unk5 = 4;
    obj->unk6 = 0;
}
