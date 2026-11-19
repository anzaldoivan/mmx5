/* Shared body (DK-5), from the banked draft of func_800F48D4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    s16 d;

    if (*(s32*)(obj + 0x24) > 0 && *(s16*)(obj + 0x7E) == 0) {
        if (obj[0x15] == 0) {
            d = D_800FA240_ovl03 - *(s16*)(obj + 0xA);
        } else {
            d = D_800FA242_ovl03 - *(s16*)(obj + 0xA);
        }
        *(s16*)(obj + 0x7E) = 1;
        *(s32*)(obj + 0x20) = (d << 16) / 40;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x24) > 0x10000) {
        set_animation(obj, 4);
        obj[0x62] = 0;
        obj[6]++;
    }
    if (obj[0x8D] == 0xFF) {
        p = g_Player;
        if (((s8*)p)[2] == 0) {
            set_animation(obj, 6);
        } else {
            set_animation(obj, 7);
        }
        obj[0x16] = 0;
        obj[0x62] = 0;
        q = g_Player;
        if (((s8*)q)[2] == 0) {
            q[0x15] = obj[0x15];
        } else if (obj[0x15] == 0) {
            q[0x15] = 0x40;
        } else {
            q[0x15] = 0;
        }
        r = g_Player;
        if (*(s16*)(r + 0xA) < D_800FA240_ovl03 ||
            D_800FA242_ovl03 < *(s16*)(r + 0xA)) {
            *(s16*)(r + 0xA) = *(s16*)(obj + 0xA);
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(r + 0xA);
        }
        t = g_Player;
        if (*(s16*)(t + 0xE) < D_800FA244_ovl03) {
            *(s16*)(t + 0xE) = *(s16*)(obj + 0xE);
        } else {
            *(s16*)(obj + 0xE) = *(s16*)(t + 0xE);
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6] += 2;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
