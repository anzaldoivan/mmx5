#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define D_8007BD4C D_80101D0C_ovl04

#define func_800532E0 func_800F6AD0_ovl04
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

extern u8 D_80101CE4_ovl04[];
extern u8 D_80101CEC_ovl04[];

void func_800F6B0C_ovl04(u8* obj) {
    u8 flags;
    s32 vx;

    flags = obj[0x93];
    if (!(flags & 8)) {
        *(u8**)(obj + 0x50) = D_80101CE4_ovl04;
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[5] = 4;
        obj[6] = 0;
        if (*(s32*)(obj + 0x20) > 0) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0xFFFE0000;
        *(u16*)(obj + 0xE) += 3;
        set_animation(obj, 0xD);
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[0x67] = 0;
    } else {
        vx = *(s32*)(obj + 0x20);
        if ((vx < 0 && (flags & 2)) || (vx > 0 && (flags & 1))) {
            obj[0x8F] = 8;
            set_animation(obj, 0xE);
            obj[4] = 2;
        }
    }
    animate_object(obj);
    move_object(obj);
}

#include "shared/func_800F6C0C_ovl04.c"

#include "shared/func_800F6D44_ovl04.c"

#define D_8007BD4C D_80101D18_ovl04

#define func_800532E0 func_800F6DFC_ovl04
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800F6E38_ovl04.c"
