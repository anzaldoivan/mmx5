#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_800D1C00[];
extern s32 func_80044DE0();

void func_800F91D8_ovl28(Ent8EF0* obj) {
    u8* g = D_800D1C00;

    g[0x24] = 1;
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.unk26 = obj->unk94;
    D_8009A1F8.unk2A = D_8009A1F8.unk28;
    if (obj->unk5C < ((s8*)g)[0xA2]) {
        if (--obj->unk7C == 0) {
            play_sound(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x30, 0x30);
        return;
    }
    D_8009A1F8.unk48 = 8;
    func_8003D2C4();
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    obj->unk5 = 3;
    obj->unk6 = 0;
}
