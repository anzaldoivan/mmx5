#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_80074DA0[];
extern u8 D_800FAB2C_ovl09[];
extern u8 D_800FAB30_ovl09[];

void func_800F14A0_ovl09(u8* obj) {
    obj[0x5C] = 4;
    obj[0x60] = 4;
    obj[0x3] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x16] = 0;
    *(u8**)(obj + 0x68) = D_800FAB30_ovl09;
    *(u8**)(obj + 0x54) = D_800FAB2C_ovl09;
    *(s32*)(obj + 0x50) = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    set_animation(obj, 2);
    obj[0x67] = 1;
    obj[0x8F] = 0;
    *(s16*)(obj + 0x8C) = 0x258;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0x10000;
        obj[0x15] = 0x40;
        *(s16*)(obj + 0xA) += 0x38;
    } else {
        *(s32*)(obj + 0x20) = 0xFFFF0000;
        obj[0x15] = 0;
        *(s16*)(obj + 0xA) -= 0x38;
    }
    obj[0x5] = 6;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x4200;
    obj[0x4] = 1;
    obj[0x6] = 0;
}

#define D_800EEBA0_ovl00 func_800F1584_ovl09
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
