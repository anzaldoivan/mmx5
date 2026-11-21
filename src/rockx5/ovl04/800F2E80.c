#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F2E80_ovl04(u8* obj) {
    obj[0x16] = 2;
    set_animation(obj, 6);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    D_1F800064[0x54] = 0;
    obj[4] = 1;
}

#define D_800EEBA0_ovl00 func_800F2ED4_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
