#include "types.h"
#include "mmx5/graphics.h"

extern s32 set_velocity_from_angle(void*, s32);
extern u8 D_801008C8_ovl07[];
extern u8 D_801008CC_ovl07[];
extern s16 D_801008D0_ovl07[];
extern u8 D_801008F0_ovl07[];
extern u8 D_801008F8_ovl07[];

void func_800F11C4_ovl07(u8* obj) {
    s16 dx;
    s32 i;
    s32 j;

    obj[4] = 1;
    obj[3] = 1;
    *(u8**)(obj + 0x68) = D_801008CC_ovl07;
    i = *(s8*)(obj + 2);
    obj[0x16] = 0;
    *(s32*)(obj + 0x54) = 0;
    *(u8**)(obj + 0x50) = D_801008C8_ovl07;
    dx = D_801008D0_ovl07[i * 2];
    j = i * 2;
    if (obj[0x15] != 0) {
        dx = -dx;
    }
    *(s16*)(obj + 0xA) += dx;
    *(u16*)(obj + 0xE) += D_801008D0_ovl07[j + 1];
    set_velocity_from_angle(obj, D_801008F0_ovl07[i]);
    obj[0x60] = 3;
    obj[0x5C] = 1;
    *(s32*)(obj + 0x20) <<= 3;
    *(s32*)(obj + 0x24) <<= 3;
    set_animation(obj, D_801008F8_ovl07[*(s8*)(obj + 2)]);
}
