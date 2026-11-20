/* Shared body (DK-5), from the banked draft of func_800F3EB8_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s16 D_800FB634_ovl09;

void DEDUP_NAME(u8* o) {
    s16 x;
    s16 t;

    if (o[0x15] == 0) {
        if (*(s32*)(o + 0x20) < 0) {
            if (*(s16*)(o + 0xA) <= D_800FB630_ovl09) {
                *(s16*)(o + 0xA) = D_800FB630_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        } else if (*(s32*)(o + 0x20) > 0) {
            if (*(s16*)(o + 0xA) >= D_800FB630_ovl09) {
                *(s16*)(o + 0xA) = D_800FB630_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s32*)(o + 0x24) > 0) {
            if (*(s16*)(o + 0xE) <= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        } else if (*(s32*)(o + 0x24) < 0) {
            if (*(s16*)(o + 0xE) >= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        }
        x = *(s16*)(o + 0xA);
        t = D_800FB630_ovl09;
    } else {
        if (*(s32*)(o + 0x20) < 0) {
            if (*(s16*)(o + 0xA) <= D_800FB62E_ovl09) {
                *(s16*)(o + 0xA) = D_800FB62E_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        } else if (*(s32*)(o + 0x20) > 0) {
            if (*(s16*)(o + 0xA) >= D_800FB62E_ovl09) {
                *(s16*)(o + 0xA) = D_800FB62E_ovl09;
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s32*)(o + 0x24) > 0) {
            if (*(s16*)(o + 0xE) <= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        } else if (*(s32*)(o + 0x24) < 0) {
            if (*(s16*)(o + 0xE) >= D_800FB634_ovl09) {
                *(s16*)(o + 0xE) = D_800FB634_ovl09;
                *(s32*)(o + 0x24) = 0;
            }
        }
        x = *(s16*)(o + 0xA);
        t = D_800FB62E_ovl09;
    }
    if (x == t && *(s16*)(o + 0xE) == D_800FB634_ovl09) {
        set_animation(o, 8);
        *(s16*)(o + 0x7C) = 0;
        *(s16*)(o + 0x7E) = -1;
        o[6]++;
    }
    animate_object(o);
    apply_object_motion(o);
}
