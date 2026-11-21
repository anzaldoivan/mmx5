#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F5990_ovl18(u8* a0) {
    s32 y = D_8009A0AA;
    s32 x = *(s16*)(a0 + 0xA);
    if ((((y - x) < 0) ? (x - y) : (y - x)) < 0xB1) {
        a0[0x7C] = 0x3C;
        a0[6]++;
    }
}

void func_800F59E8_ovl18(u8* obj) {
    if (--obj[0x7C] == 0) {
        play_sound(5, 0x1F, obj);
        set_animation(obj, 1);
        obj[6]++;
    }
}

extern u8 D_800F7F74_ovl18[];
extern u8 D_800F7F78_ovl18[];

void func_800F5A4C_ovl18(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x68) = D_800F7F74_ovl18;
        *(u8**)(obj + 0x54) = D_800F7F78_ovl18;
        obj[0x7C] = 0x96;
        obj[6]++;
    }
}

void func_800F5AA8_ovl18(u8* o) {
    animate_object(o);
    if (--o[0x7C] == 0) {
        set_animation(o, 2);
        *(s32*)(o + 0x68) = 0;
        *(s32*)(o + 0x54) = 0;
        o[6]++;
    }
}

void func_800F5B04_ovl18(u8* arg0) {
    animate_object();
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[3] = 0;
        arg0[6] = 0;
    }
}
