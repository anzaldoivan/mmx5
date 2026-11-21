#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F2948_ovl20(u8* obj) {
    if (((s8*)obj)[2] == 3) {
        animate_object(obj);
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_8002D89C(obj);
    }
}

extern u8 D_800D1C00[];
extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F29A0_ovl20(u8* a0) {
    s8* p = (s8*)D_800D1C00;
    s32 v = p[0x28];

    if (v < 8 && p[0x2D] == 0) {
        set_animation_frame(a0, 3, v);
        func_8002D9EC(a0, 0x40, 0x40);
    } else {
        a0[3] = 0;
    }
}

#define D_800EEBA0_ovl00 func_800F2A08_ovl20
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern u8 D_800D1C78[];

void func_800F2A28_ovl20(u8* a0) {
    if (D_800D1C78[1] >= 5) {
        clear_object_slot();
    } else {
        func_8002D9EC(a0, 0x40, 0x40);
    }
}

#include "shared/func_800F2A6C_ovl20.c"

#define func_800F2A6C_ovl20 func_800F2A90_ovl20
#include "shared/func_800F2A6C_ovl20.c"
#undef func_800F2A6C_ovl20
