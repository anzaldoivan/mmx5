#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

extern u8 D_800FB2D0_ovl09[];
extern u8 D_800FB2DC_ovl09[];

void func_800F8D10_ovl09(u8* a0) {
    a0[0x62] = 2;
    a0[0x60] = 8;
    *(u8**)(a0 + 0x50) = D_800FB2D0_ovl09;
    *(u8**)(a0 + 0x68) = D_800FB2DC_ovl09;
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    a0[6]++;
}

void func_800F8D54_ovl09(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 1);
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x38000;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}

void func_800F8DB8_ovl09(u8* o) {
    move_object(o);
    if (*(s16*)(o + 0xE) < 0x821) {
        o[4] = 4;
        o[5] = 0;
        o[6] = 0;
    }
}
