#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s8 D_800FA683_ovl26;

void func_800F45CC_ovl26(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (D_800FA683_ovl26 == 0 && *(s16*)(obj + 0xE) >= 0x1240) {
        D_800FA683_ovl26 = 1;
    }
    if (*(s16*)(obj + 0xE) >= 0x1260) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        set_animation(obj, 8);
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
    }
}
