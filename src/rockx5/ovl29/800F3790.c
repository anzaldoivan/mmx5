#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

void func_800F3790_ovl29(u8* obj) {
    u8* p;
    s32 v;

    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    set_animation(obj, 3);
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 2;
        *(u8**)(p + 0x50) = obj;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x26;
        p[2] = 3;
        *(u8**)(p + 0x50) = obj;
    }
    obj[0x67] = 1;
    play_sound(2, 0xAC, obj);
    v = 0xFFFF4000;
    obj[6]++;
    if (obj[0x15] != 0) {
        v = 0xC000;
    }
    *(s32*)(obj + 0x20) = v;
    *(s32*)(obj + 0x24) = 0x38000;
    *(s32*)(obj + 0x28) = 0x800;
    *(s32*)(obj + 0x2C) = -0x800;
    *(u16*)(obj + 0x88) = *(u16*)(obj + 0xE);
}

extern u8 D_800F9894_ovl29[];
extern u8 D_800F98A0_ovl29[];
extern s16 D_800FA648_ovl29;
extern s16 D_800FA64C_ovl29;

void func_800F389C_ovl29(u8* obj) {
    s16 x;
    s16 d;
    s32 v;

    if (*(s8*)(obj + 0x45) != 0) {
        *(u8**)(obj + 0x50) = D_800F98A0_ovl29;
    } else {
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        obj[0x67] = 0;
        play_sound(2, 0xAF, obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        d = D_8009A0AA;
        x = *(s16*)(obj + 0xA);
        if (x < d) {
            if (x < D_800FA648_ovl29 - 0x50) {
                obj[0x15] = 0x40;
            } else {
                obj[0x15] = 0;
            }
        } else if (x < D_800FA64C_ovl29 + 0x50) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        v = 0xFFF80000;
        if (obj[0x15] != 0) {
            v = 0x80000;
        }
        *(s32*)(obj + 0x20) = v;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        apply_object_motion(obj);
    }
    animate_object(obj);
}
