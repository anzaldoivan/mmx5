#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];

void func_800F4244_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0x12);
        D_800D1C00[0x24] = 1;
        D_800D1C00[0x25] = 0;
        *(s16*)(obj + 0x7E) = 3;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
