/* Shared body (DK-5), from the banked draft of func_800F50E0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA24E_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 v;
    s32 r;

    v = *(s32*)(obj + 0x20);
    if (v < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
        *(s16*)(obj + 0xA) = D_800FA242_ovl03;
    clear:
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s16*)(obj + 0xE) >= D_800FA24E_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA24E_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        r = random_byte() & 0xF;
        if (r < 5) {
            obj[7] = 0;
        } else {
            if (r < 0xC) {
                obj[7] = 3;
            } else if (r < 0xE) {
                obj[7] = 6;
            } else {
                obj[7] = 9;
            }
        }
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
