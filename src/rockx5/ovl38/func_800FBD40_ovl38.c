#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void func_800FBD40_ovl38(EntBD40* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        play_sound(0, 0xE, 0);
        obj->unk7C = 2;
    }
    if (++obj->unk5C >= D_800D1CA2) {
        ((s32(*)())func_8003D2C4)();
        obj->unk6++;
    }
}
