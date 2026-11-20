/* Shared body (DK-5), from the banked draft of func_800F7A0C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(u8* obj) {
    if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x50) {
        *(s16*)(obj + 0xA) += 1;
        return;
    }
    if (D_800FA058_ovl11 + 0x50 < *(s16*)(obj + 0xA)) {
        *(s16*)(obj + 0xA) -= 1;
        return;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        set_animation(obj, 1);
    }
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
        return;
    }
    move_object(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 30;
        obj[6]++;
    }
}
