#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/object.h"

extern void func_800F0978_ovl29(u8* obj);
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800F91A8_ovl29[];
extern u8 D_800F91AC_ovl29[];
extern u8 D_800F91B0_ovl29[];
extern u8 D_800F9304_ovl29[];

void func_800EFD00_ovl29(u8* obj) {
    s8 v;
    u8 b;
    s32 x;
    s32 y;

    obj[0x5C] = 9;
    *(s32*)(obj + 0x80) = 0;
    *(s32*)(obj + 0x84) = 0;
    *(s32*)(obj + 0x88) = 0;
    *(s32*)(obj + 0x8C) = 0;
    *(s32*)(obj + 0x90) = 0;
    *(s32*)(obj + 0x94) = 0;
    obj[0x60] = 3;
    obj[0x61] = 0;
    *(u8**)(obj + 0x58) = D_800750C0;
    b = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800F9304_ovl29;
    obj[0x16] = 6;
    *(u8**)(obj + 0x68) = D_800F91B0_ovl29;
    *(u8**)(obj + 0x54) = D_800F91A8_ovl29;
    x = *(s32*)(obj + 0x8);
    y = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x50) = D_800F91AC_ovl29;
    obj[0x14] = b;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = y;
    func_800F0978_ovl29(obj);
    v = (s8)obj[2];
    switch (v) {
    case 0:
        obj[0x80] = 0;
        obj[0x8C] = 0;
        *(s16*)(obj + 0x7C) = 0x5A;
        obj[4] = 1;
        obj[5] = 3;
        obj[6] = 0;
        break;
    case 1:
        *(s16*)(obj + 0x7C) = 0xA;
        obj[0x80] = 0;
        obj[0x8C] = 0;
        obj[4] = v;
        obj[5] = 5;
        obj[6] = 0;
        break;
    }
    set_animation(obj, 0x14);
}

extern void set_velocity_from_angle(void*, s32);

void func_800EFE38_ovl29(u8* obj) {
    u8* child;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7E) == 0) {
        if (obj[0x80] == 0) {
            set_animation(obj, obj[0x88] + 2);
        } else {
            set_animation(obj, obj[0x88] + 7);
        }
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x1B;
            child[2] = obj[0x88] + obj[0x80] * 5;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            child[0x14] = obj[0x14];
            *(s32*)(child + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            child[0x15] = obj[0x15];
            set_velocity_from_angle(child, obj[0x84]);
            child[4] = 0;
        }
        if (--*(s16*)(obj + 0x7C) == 0) {
            *(s16*)(obj + 0x7C) = 0x1E;
            obj[6] = 3;
            obj[0x8C] = 0;
            return;
        }
        *(s16*)(obj + 0x7E) = 0x10;
    }
}

extern u8 func_80030AE4(u8*, s16, s16);

void func_800EFF90_ovl29(u8* o) {
    u8* p;
    u8* d;
    s16 x;
    s16 y;
    s32 diff;

    move_object(o);
    animate_object(o);
    p = *(u8**)(o + 0x68);
    x = *(s16*)(o + 0xA) + (s8)p[0];
    y = *(s16*)(o + 0xE) + (s8)p[1] + p[3] + 16;
    if (o[0x15] == 0) {
        x -= 16;
    } else {
        x += 16;
    }
    if (func_80030AE4(o, x, y) == 0) {
        goto kill; // !FAKE: goto kept for the matching branch layout
    }
    if (o[0x15] == 0) {
        u8* d = g_Player;
        if (*(s16*)(d + 0xA) - *(s16*)(o + 0xA) > 0x40) {
            o[0x15] = 0x40;
            *(s32*)(o + 0x20) = 0x1CCCC;
        } else if (o[0x70] & 2) {
            set_animation(o, 1);
            o[5] = 4;
            o[6] = 0;
        }
    } else {
        u8* d = g_Player;
        if (*(s16*)(o + 0xA) - *(s16*)(d + 0xA) > 0x40) {
            o[0x15] = 0;
            *(s32*)(o + 0x20) = -0x1CCCC;
        } else if (o[0x70] & 1) {
            set_animation(o, 1);
            o[5] = 4;
            o[6] = 0;
        }
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        o[0x8C] = 1;
        d = g_Player;
        diff = *(s16*)(d + 0xE) - *(s16*)(o + 0xE);
        if (diff >= 0) {
            if (diff > 0x20) {
                goto two; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            if (*(s16*)(o + 0xE) - *(s16*)(d + 0xE) <= 0x20) {
                goto rnd; // !FAKE: goto kept for the matching branch layout
            }
            goto two; // !FAKE: goto kept for the matching branch layout
        }
    rnd:
        if ((u32)(random_byte() & 0xF) >= 3) {
        kill:
            set_animation(o, 1);
            o[5] = 4;
        } else {
        two:
            o[5] = 2;
        }
        o[6] = 0;
    }
}
