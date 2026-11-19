/* Shared body (DK-5), from the banked draft of func_800F3B18_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA246_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24A_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 e1;
    s32 e2;
    s32 d1;
    s32 d2;
    s16 x;
    s16 a;
    u8* p;
    u8* q;
    s32 e;

    set_animation(obj, 1);
    p = g_Player;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    if (*(s16*)(obj + 0xE) < D_800FA24A_ovl03) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d1 = D_800FA244_ovl03;
        e1 = *(s16*)(obj + 0xE) + 1;
        a = ratan2(d1 - e1, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 1;
    } else if (q = g_Player, ((s8*)q)[2] == 0) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d2 = D_800FA246_ovl03;
        e2 = *(s16*)(obj + 0xE) - 1;
        a = ratan2(d2 - e2, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 3;
    } else {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
            obj[0x8E] = 2;
        } else {
            x = D_800FA242_ovl03 + 1;
            obj[0x8E] = 3;
        }
        e = *(s16*)(obj + 0xE) - 1;
        a = ratan2(D_800FA246_ovl03 - e, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 5;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
