#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

void func_800F19DC_ovl09(u8* a0) {
    move_object(a0);
    ((s32(*)())func_8002FB58)(a0);
    if (a0[0x70] & 4) {
        *(s32*)(a0 + 0x24) = 0;
        *(s32*)(a0 + 0x2C) = 0;
        *(s32*)(a0 + 0x20) = 0;
        *(s32*)(a0 + 0x28) = 0;
        a0[0x67] = 0;
        if (a0[0x15] == 0) {
            a0[0x8F] = 1;
            a0[0x5] = 2;
        } else {
            a0[0x8F] = 0;
            a0[0x5] = 3;
        }
        a0[0x6] = 0;
    }
}

void func_800F1A5C_ovl09(u8* obj) {
    if (*(s32*)(obj + 0x24) <= -0x80000) {
        *(s32*)(obj + 0x24) = -0x80000;
    }
    apply_object_motion(obj);
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 0;
        if (obj[0x15] == 0) {
            obj[0x8F] = 0;
            obj[5] = 2;
        } else {
            obj[0x8F] = 1;
            obj[5] = 3;
        }
        obj[6] = 0;
    }
}

extern u8 D_800FAB2C_ovl09[];

void func_800F1AF8_ovl09(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x50) = D_800FAB2C_ovl09;
        set_animation(obj, 3);
        obj[5] = 5;
    }
}
