/* Shared body (DK-5), from the banked draft of func_800F55D0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 v;

    v = *(s32*)(obj + 0x20);
    if (v < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (v > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
        clear:
            *(s32*)(obj + 0x20) = 0;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        D_800D50DC = 0;
        D_8009A42C = 0;
        D_80093E66 = 0;
        func_8002C218();
        set_animation(obj, 0xA);
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
