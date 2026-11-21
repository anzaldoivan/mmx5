#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F2FE8_ovl08(u8* obj) {
    set_animation(obj, 4);
    obj[0x16] = 0x20;
    obj[3] = 0;
    obj[0x15] = 0;
    obj[4] = 1;
    obj[5] = 0;
    obj[6] = 0;
}

void func_800F3030_ovl08(u8* a0) {
    u8* p = *(u8**)(a0 + 0x50);

    if (((s8*)p)[4] == 2) {
        a0[4] = 2;
        a0[5] = 0;
        a0[3] = 0;
    } else {
        *(s16*)(a0 + 0xA) = *(s16*)(p + 0xA);
        *(s16*)(a0 + 0xE) = *(s16*)(p + 0xE) - 0xA8;
        func_8002D9EC(a0, 0x20, 0x20);
        if (((s8*)a0)[3] == 0) {
            a0[3] = p[3];
        }
    }
}

#define D_800EEBA0_ovl00 func_800F30BC_ovl08
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
