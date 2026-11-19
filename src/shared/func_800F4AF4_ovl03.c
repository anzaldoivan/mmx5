/* Shared body (DK-5), from the banked draft of func_800F4AF4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(u8* o) {
    if (*(s32*)(o + 0x20) < 0) {
        if (*(s16*)(o + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(o + 0xA) = D_800FA240_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    } else if (*(s32*)(o + 0x20) > 0) {
        if (*(s16*)(o + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(o + 0xA) = D_800FA242_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    }
    if (*(s16*)(o + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(o + 0xE) = D_800FA244_ovl03;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
    }
    if (*(s32*)(o + 0x20) == 0 && *(s32*)(o + 0x24) == 0) {
        set_animation(o, 1);
        o[5] = D_800FA0BC_ovl03[o[0x92]][o[0x93]++];
        o[6] = 0;
    }
    animate_object(o);
    apply_object_motion(o);
}
