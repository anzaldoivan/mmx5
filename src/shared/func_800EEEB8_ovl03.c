/* Shared body (DK-5), from the banked draft of func_800EEEB8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void DEDUP_NAME(u8* obj) {
    s32 lim;
    s32 over;

    *(s32*)(obj + 0x24) = 0;
    if (*(s8*)(obj + 0x2) == 0) {
        if (obj[0x70] & 2) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            obj[0x5] = 4;
            obj[0x6] = 0;
        }
        lim = -0x20000;
        over = *(s32*)(obj + 0x20) < lim;
    } else {
        if (obj[0x70] & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            obj[0x5] = 4;
            obj[0x6] = 0;
        }
        lim = 0x20000;
        over = *(s32*)(obj + 0x20) > lim;
    }
    if (over) {
        *(s32*)(obj + 0x20) = lim;
    }
    if (D_8009A420_as_s32 == D_8009A420_as_s32 / 30 * 30) {
        play_sound(5, 9, obj);
    }
    apply_object_motion(obj);
    animate_object(obj);
}
