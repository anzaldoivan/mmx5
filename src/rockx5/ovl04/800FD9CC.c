#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800FD9CC_ovl04(u8* o) {
    animate_object();
    move_object(o);
    if (*(s8*)(o + 0x46) == 0) {
        *(u8*)(o + 4) = 2;
    }
}

void func_800FDA0C_ovl04(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) >= -0x10000) {
        *(s32*)(obj + 0x20) = -0x10000;
    }
}

#define move_object apply_object_motion

#define func_800EF574_ovl09 func_800FDA50_ovl04
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
#undef move_object

#define func_800EF574_ovl09 func_800FDA7C_ovl04
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
