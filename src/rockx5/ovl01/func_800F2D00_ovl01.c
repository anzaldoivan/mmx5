#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_800F2F44_ovl01(u8* arg0);

void func_800F2D00_ovl01(u8* obj) {
    s8 f;

    animate_object(obj);
    apply_object_motion(obj);
    func_800F2F44_ovl01(obj);
    f = *(s8*)(obj + 0x45);
    if (f != 0) {
        set_animation(obj, 2);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[5] = 3;
        obj[6] = 0;
        obj[0x15] ^= 0x40;
    }
}
