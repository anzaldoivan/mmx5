#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

#define func_800F1080_ovl04 func_800F18B0_ovl18
#include "shared/func_800F1080_ovl04.c"
#undef func_800F1080_ovl04

#define D_8007BD4C D_800F798C_ovl18

#define func_800532E0 func_800F1984_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

void func_800F19C0_ovl18(u8* o) {
    switch ((s8)o[2]) {
    case 0x10:
        *(s32*)(o + 0x20) = 0x5000;
        *(s32*)(o + 0x28) = 0x1000;
        *(s32*)(o + 0x24) = -0xA000;
        o[6] = 1;
        break;
    case 0x11:
        *(s32*)(o + 0x20) = 0x5000;
        *(s32*)(o + 0x28) = 0x1000;
        *(s32*)(o + 0x24) = 0;
        o[6] = 1;
        break;
    case 0x12:
        *(s32*)(o + 0x20) = 0x5000;
        *(s32*)(o + 0x28) = 0x1000;
        *(s32*)(o + 0x24) = 0xA000;
        o[6] = 1;
        break;
    case 0x20:
        *(s16*)(o + 0x7C) = 60;
        *(s32*)(o + 0x20) = 0x28000;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = -0x14000;
        o[6] = 2;
        break;
    case 0x21:
        *(s32*)(o + 0x20) = 0x28000;
        *(s16*)(o + 0x7C) = 60;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        o[6] = 2;
        break;
    case 0x22:
        *(s16*)(o + 0x7C) = 60;
        *(s32*)(o + 0x20) = 0x28000;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0x14000;
        o[6] = 2;
        break;
    }
    *(s32*)(o + 0x2C) = 0;
}

#define D_800EEBA0_ovl00 func_800F1ACC_ovl18
#define func_8002D720 apply_object_motion
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define func_800F12BC_ovl04 func_800F1AEC_ovl18
#include "shared/func_800F12BC_ovl04.c"
#undef func_800F12BC_ovl04

#define D_8007BD4C D_800F7998_ovl18

#define func_800532E0 func_800F1B34_ovl18
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define func_800F1340_ovl04 func_800F1B70_ovl18
#include "shared/func_800F1340_ovl04.c"
#undef func_800F1340_ovl04

#define D_800EEBA0_ovl00 func_800F1C20_ovl18
#define func_8002D720 move_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
