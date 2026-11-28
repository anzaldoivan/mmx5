#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

extern u8 D_8009A0B4;
extern u8 D_800FB278_ovl09[];

void func_800F7734_ovl09(u8* e) {
    u8* o;

    if (++*(u16*)(e + 0x84) == 0x60) {
        o = func_8002D27C();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x25;
            o[2] = 1;
            o[0x14] = D_8009A0B4;
            o[0x16] = 1;
            o[0x15] = e[0x15];
            *(u16*)(o + 0x40) = *(u16*)(e + 0x40);
            *(u16*)(o + 0x42) = *(u16*)(e + 0x42);
            *(s32*)(o + 0x3C) = *(s32*)(e + 0x3C);
            *(u8**)(o + 0x30) = D_800FB278_ovl09;
            *(s32*)(o + 0x8) = *(s32*)(e + 0x8);
            *(s32*)(o + 0xC) = *(s32*)(e + 0xC);
            o[0x54] = 0;
            *(u8**)(e + 0x7C) = o;
            *(u16*)(e + 0x84) = 0;
            e[6]++;
        }
    }
}

extern u8 D_8009A0B4;
extern u8 D_800FB278_ovl09[];

void func_800F7808_ovl09(u8* arg0) {
    u8* p;

    if (++*(u16*)(arg0 + 0x84) == 0x60) {
        p = (u8*)func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x25;
            p[2] = 2;
            p[0x16] = 0x10;
            p[0x14] = D_8009A0B4;
            p[0x15] = arg0[0x15];
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(arg0 + 0x42);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u8**)(p + 0x30) = D_800FB278_ovl09;
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
            p[0x54] = 0;
            *(u8**)(arg0 + 0x80) = p;
            *(u16*)(arg0 + 0x84) = 0;
            arg0[6]++;
            play_sound(5, 0x16, arg0);
        }
    }
}

extern u8 D_8009A0B5;

void func_800F78F4_ovl09(u8* obj) {
    u8* child = *(u8**)(obj + 0x80);
    s8 v = *(s8*)(child + 0x45);

    if (v == 1) {
        set_animation(child, 4);
        *(*(u8**)(obj + 0x7C) + 0x54) = v;
        *(s16*)(obj + 0x84) = 0;
        ((s32(*)())func_8003D29C)(0x16, D_8009A0B5);
        obj[6]++;
    }
}

void func_800F796C_ovl09(u8* obj) {
    if (++*(u16*)(obj + 0x84) == 50) {
        obj[5] = 3;
        obj[6] = 0;
    }
}
