#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern u8 D_800FD5AC_ovl01[];
extern u8 D_800FD5A8_ovl01[];

void func_800FA474_ovl01(X4_Obj* self) {
    s8 v;

    animate_object(self);
    v = *(s8*)&self->pad44[1];
    if (v == 1) {
        self->unk60 = 6;
        self->x_vel.val = 0;
        self->unk28 = 0;
        self->y_vel.val = 0x60000;
        self->unk2C = 0xE00;
        set_animation(self, 0xE);
        self->unk54 = D_800FD5AC_ovl01;
        self->unk50 = D_800FD5A8_ovl01;
        self->unk68 = 0;
        self->unk6 = v;
    }
}

extern signed char D_800D1C0C;

void func_800FA4F8_ovl01(u8* obj) {
    s32 below;

    animate_object(obj);
    apply_object_motion(obj);
    if (D_800D1C0C != 12) {
        below = *(s16*)(obj + 0xE) < 177;
    } else {
        below = *(s16*)(obj + 0xE) < -47;
    }
    if (below) {
        *(s16*)(obj + 0x7C) = 60;
        obj[6] = 2;
    }
}

extern s8 D_800D1C0C;
extern u8 D_800FD5B0_ovl01[];
extern u8 D_800FD5B4_ovl01[];
extern u16 D_800FDA5C_ovl01[];
extern u16 D_800FDA98_ovl01[];

void func_800FA564_ovl01(u8* obj) {
    s32 base;
    u16 v;

    base = 0x1F0;
    if (D_800D1C0C != 0xC) {
        base = 0x24F0;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4000;
        set_animation(obj, 2);
        obj[0x15] = 0x40;
        obj[0x62] = 0;
        *(u8**)(obj + 0x54) = D_800FD5B4_ovl01;
        *(u8**)(obj + 0x50) = D_800FD5B0_ovl01;
        v = D_800FDA98_ovl01[D_800FDA5C_ovl01[(D_8009A0AA - base) / 16]];
        obj[6] = 3;
        *(u16*)(obj + 0xA) = v;
    }
}

extern signed char D_800D1C0C;
extern u8 D_800FD60C_ovl01[];

void func_800FA648_ovl01(u8* obj) {
    s32 limit = 0x40;

    if (D_800D1C0C != 12) {
        limit = 0x120;
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (limit < *(s16*)(obj + 0xE)) {
        *(u8**)(obj + 0x68) = D_800FD60C_ovl01;
        obj[6] = 4;
    }
}

extern void start_pad_vibration(s32);
extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD9CC_ovl01[];

void func_800FA6BC_ovl01(u8* obj) {
    u16 x;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        *(s32*)(obj + 0x68) = 0;
        func_800FB418_ovl01(0x1E, D_800FD9CC_ovl01, obj, 2);
        x = *(u16*)(obj + 0xA);
        func_80050650(0x21, x - 0x50, *(s16*)(obj + 0xE), x + 0x50,
                      *(u16*)(obj + 0xE) + 0x80, 6);
        play_sound(2, 0xC, obj);
        func_8002A600(0x28, 4, 2);
        set_animation(obj, 0xA);
        obj[6] = 5;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
}
