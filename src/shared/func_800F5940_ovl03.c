/* Shared body (DK-5), from the banked draft of func_800F5940_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA250_ovl03;
extern s16 D_800FA252_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 i;
    u8* p;
    u8* d;

    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    }
    if (*(s32*)(obj + 0x24) < 0) {
        if (*(s16*)(obj + 0xE) >= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    } else if (*(s32*)(obj + 0x24) > 0) {
        if (*(s16*)(obj + 0xE) <= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        if (random_byte() & 1) {
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 1;
        } else {
            set_animation(obj, 8);
            for (i = 0; i < 3; i++) {
                p = func_8002D1A4();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0x15;
                    p[2] = i;
                    *(u8**)(p + 0x7C) = obj;
                }
            }
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 2;
        }
    }
    d = g_Player;
    if (*(s16*)(d + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
