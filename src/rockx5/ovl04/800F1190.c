#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F1190_ovl04(u8* o) {
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

#define D_800EEBA0_ovl00 func_800F129C_ovl04
#define func_8002D720 apply_object_motion
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#include "shared/func_800F12BC_ovl04.c"
