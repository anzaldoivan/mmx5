/* Shared body (DK-5), from the banked draft of func_800F5384_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    s8 st = *(s8*)(obj + 7);
    u8 st2 = obj[7];

    if (st == 2 || st == 5 || st == 8 || st == 11) {
        if (++*(s16*)(obj + 0x7C) == 100) {
            set_animation(obj, 1);
            obj[5] = D_800FA0BC_ovl03[obj[0x92]][obj[0x93]++];
            obj[6] = 0;
        }
    } else if (st == 0 || st == 3 || st == 6 || st == 9) {
        if (++*(s16*)(obj + 0x7C) == 0x93) {
            obj[7]++;
            obj[6] -= 2;
        }
    } else {
        if (++*(s16*)(obj + 0x7C) == 100) {
            obj[7] = st2 + 1;
            obj[6] -= 2;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
