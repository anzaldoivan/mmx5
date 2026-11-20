/* Shared body (DK-5), from the banked draft of func_800F4C10_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8003D010(s8 dmg);
extern void start_pad_vibration(s32);
extern s16 D_800FA248_ovl03;
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    u8* p;
    s16 x;
    s16 a;
    s32 y;

    p = g_Player;
    if (((s8*)p)[2] == 0) {
        p[0x15] = obj[0x15];
    } else if (obj[0x15] == 0) {
        p[0x15] = 0x40;
    } else {
        p[0x15] = 0;
    }
    if (++*(s16*)(obj + 0x7C) == 40) {
        if (*(s16*)(obj + 0x7E) == 4) {
            set_animation(obj, 1);
            obj[0x16] = 5;
            if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
                x = D_800FA240_ovl03 - 1;
            } else {
                x = D_800FA242_ovl03 + 1;
            }
            y = *(s16*)(obj + 0xE) + 1;
            a = ratan2(D_800FA244_ovl03 - y, x - *(s16*)(obj + 0xA));
            *(s32*)(obj + 0x20) = rcos(a) * 48;
            *(s32*)(obj + 0x24) = -rsin(a) * 48;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x50) = 0;
            *(s16*)(obj + 0x7C) = 0;
            obj[6]++;
            animate_object(obj);
            apply_object_motion(obj);
            return;
        }
        func_8003D010(1);
        start_pad_vibration(8);
        if (g_Player[0x5C] == 0x80) {
            set_animation(obj, 1);
        }
        {
            u8* q = D_800D1C00;
            if (((s8*)obj)[0x5C] <= ((s8*)q)[0xA2] - 2) {
                obj[0x5C] += 2;
            } else {
                obj[0x5C] = q[0xA2];
            }
        }
        {
            u8* q = D_800D1C00;
            if (((s8*)obj)[0x5C] > ((s8*)q)[0xA2]) {
                obj[0x5C] = q[0xA2];
            }
        }
        *(s16*)(obj + 0x7C) = 0;
        (*(s16*)(obj + 0x7E))++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
