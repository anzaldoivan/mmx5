#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

extern u8* find_free_visual_obj(void);
extern s8 D_8009A0FC;

void func_800EFA80_ovl06(u8* obj) {
    u8* p;
    s32 press;
    s32 hit;
    s32 moved;
    s32 v;

    if (((s8*)obj)[6] == 0) {
        *(s32*)(obj + 0x24) = 0x58000;
        obj[6] = 1;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
        if (((s8*)obj)[2] == 0) {
            p = find_free_visual_obj();
            if (p != 0) {
                p[0] = obj[0];
                p[1] = 0xC;
                p[2] = 6;
                *(s32*)(p + 8) = *(s32*)(obj + 8);
                *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                p[0x16] = obj[0x16];
                p[0x15] = obj[0x15];
                *(u8**)(p + 0x50) = obj;
            }
        }
        set_animation(obj, 2);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x2B;
            g_Player[6] = 0;
        }
        obj[0x87] = 0;
        if (((s8*)obj)[2] == 0) {
            play_sound(5, 0xF, 0);
        } else {
            play_sound(5, 3, 0);
        }
    }
    if (*(u16*)(obj + 0x8A) & 0x30) {
        press = 1;
        if (((s8*)obj)[2] != 0) {
            press = obj[0x7E] == 0;
        }
    } else {
        press = 0;
    }
    if (press) {
        obj[5] = 6;
        obj[6] = 0;
        return;
    }
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (!(*(u16*)(obj + 0x8A) & 0x80)) {
            goto zero; // !FAKE: goto kept for the matching branch layout
        }
        hit = 1;
    } else if (D_8009A0FC == -0x80) {
        hit = 1;
    } else {
    zero:
        hit = 0;
    }
    if (hit) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        *(s32*)(obj + 0x20) = 0;
        if (*(u16*)(obj + 0x88) & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (*(u16*)(obj + 0x88) & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (moved) {
            v = *(s16*)(obj + 0x98) << 8;
            if (obj[0x15] == 0) {
                v = -v;
            }
            *(s32*)(obj + 0x20) = v;
        }
        if (!(obj[0xA8] & 4) && *(s32*)(obj + 0x24) >= 0 &&
            (*(u16*)(obj + 0x88) & 0x80)) {
            apply_object_motion(obj);
            return;
        }
        obj[5] = 0xC;
        obj[6] = 0;
    }
}
