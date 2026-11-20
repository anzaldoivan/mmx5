#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"

extern S16x11 D_800FA0AC_ovl35;
extern S32x3 D_800FA0C4_ovl35;
extern u8 D_800FFBC0_ovl35[];

extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800FD5C4_ovl35(u8* obj) {
    S16x11 spd;
    S32x3 vel;
    u8* p;
    s32 ang;
    s16 r;
    s32 v0, v1, v2;

    v0 = D_800FA0C4_ovl35.v[0];
    v1 = D_800FA0C4_ovl35.v[1];
    v2 = D_800FA0C4_ovl35.v[2];
    p = *(u8**)(obj + 0x7C);
    spd = D_800FA0AC_ovl35;
    vel.v[0] = v0;
    vel.v[1] = v1;
    vel.v[2] = v2;
    *(s16*)(obj + 0x40) = *(s16*)(p + 0x40);
    *(s16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(u8**)(obj + 0x30) = D_800FFBC0_ovl35;
    *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
    obj[0x14] = 0;
    obj[0x16] = 1;
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    if (random_byte() & 1) {
        obj[0x15] = 0;
    } else {
        obj[0x15] = 0x40;
    }
    ang = (random_byte() & 0xFF) << 8;
    ang = (random_byte() & 0xFF) | (u16)ang;
    r = spd.v[random_byte() % 11];
    ang &= 0xFFF;
    *(s16*)(obj + 0xA) =
        *(s16*)(*(u8**)(obj + 0x7C) + 0xA) + rcos(ang) * r / 4096;
    *(s16*)(obj + 0xE) =
        *(s16*)(*(u8**)(obj + 0x7C) + 0xE) - rsin(ang) * r / 4096;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -vel.v[random_byte() % 3];
    } else {
        *(s32*)(obj + 0x20) = vel.v[random_byte() % 3];
    }
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 0;
    obj[0x60] = 0;
    if (random_byte() & 1) {
        set_animation(obj, 9);
    } else {
        set_animation(obj, 10);
    }
    obj[0x7] = random_byte() % 48 + 0x30;
    obj[0x4]++;
    obj[0x5] = 0;
}
