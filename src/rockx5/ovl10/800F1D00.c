#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

#define D_800EEC60_ovl00 func_800F1D00_ovl10
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

void func_800F1D08_ovl10(u8* obj) {
    if (obj[0x70] & 8) {
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x24) = 0;
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
            set_animation(obj, 9);
            *(s32*)(obj + 0x20) = 0x13000;
            obj[5] = 3;
        } else {
            obj[0x15] = 0;
            set_animation(obj, 8);
            *(s32*)(obj + 0x20) = -0x13000;
            obj[5] = 7;
        }
    } else {
        apply_object_motion(obj);
    }
}

#define SCR D_1F80004C.scr82
extern u8 D_800FB6B2_ovl10;
extern u8 D_800FB6B3_ovl10;

void func_800F1DA8_ovl10(Ent14C8* e) {
    if (e->flags70 & 8) {
        SCR->box.c = D_800FB6B2_ovl10;
        e->f20 = 0x13000;
        e->f24 = 0;
        e->state = 3;
        e->dir = 0x40;
        set_animation(e, 9);
    } else if (!(e->flags70 & 2)) {
        e->f20 = 0;
        e->f24 = 0x13000;
        e->state = 0xA;
        e->dir = 0;
        set_animation(e, 0xA);
    } else if (SCR->flags82 & 0x10) {
        SCR->box.d = D_800FB6B3_ovl10;
        SCR->flags82 &= ~0x10;
    }
    move_object(e);
}
#undef SCR

#define SCR D_1F80004C.scr82
extern u8 D_800FB6B2_ovl10;
extern u8 D_800FB6B3_ovl10;

void func_800F1EA4_ovl10(Ent14C8* e) {
    if (e->flags70 & 8) {
        SCR->box.c = D_800FB6B2_ovl10;
        e->f20 = 0xFFFED000;
        e->f24 = 0;
        e->state = 7;
        e->dir = 0;
        set_animation(e, 8);
    } else if (!(e->flags70 & 1)) {
        e->f20 = 0;
        e->f24 = 0x13000;
        e->state = 6;
        e->dir = 0x40;
        set_animation(e, 0xA);
    } else if (SCR->flags82 & 0x10) {
        SCR->box.d = D_800FB6B3_ovl10;
        SCR->flags82 &= ~0x10;
    }
    move_object(e);
}
