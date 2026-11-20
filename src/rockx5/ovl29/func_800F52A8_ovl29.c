#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F989C_ovl29[];
extern u8 D_800F9894_ovl29[];

void func_800F52A8_ovl29(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s8*)(obj + 0x45) == 2) {
        *(u8**)(obj + 0x50) = D_800F989C_ovl29;
    }
    if (obj[0x15] != 0 ? *(s32*)(obj + 0x20) < 0 : *(s32*)(obj + 0x20) >= 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
    }
    if (*(s32*)(obj + 0x24) < 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
        set_animation(obj, 7);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
}
