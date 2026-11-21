#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F2A7C_ovl08(u8* obj) {
    set_animation(obj, 10);
    obj[0x16] = 1;
    obj[0x3] = 1;
    obj[0x15] = 0;
    obj[0x4] = 1;
    obj[0x5] = 0;
    obj[0x6] = 0;
}

void func_800F2AC0_ovl08(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[3] = 0;
        obj[4] = 2;
    }
}

#define D_800EEBA0_ovl00 func_800F2AFC_ovl08
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
