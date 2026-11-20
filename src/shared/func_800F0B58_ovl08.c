/* Shared body (DK-5), from the banked draft of func_800F0B58_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) != 0) {
        return;
    }
    obj[0x8A] = 1;
    if (obj[0x15] == 0) {
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            goto hit; // !FAKE: goto kept for the matching branch layout
        }
        goto miss; // !FAKE: goto kept for the matching branch layout
    }
    if (D_8009A0AA < *(s16*)(obj + 0xA)) {
    hit:
        set_animation(obj, 2);
        obj[5] = 4;
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 1;
        return;
    }
miss:
    *(s16*)(obj + 0x7C) = 20;
    obj[6] = 1;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = 0xFFFC0000;
    } else {
        *(s32*)(obj + 0x20) = 0x40000;
    }
}
