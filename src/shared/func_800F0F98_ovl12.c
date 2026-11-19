/* Shared body (DK-5), from the banked draft of func_800F0F98_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80091C44;

void DEDUP_NAME(u8* obj) {
    if (D_80091C44 == 0) {
        set_animation(obj, 12);
        obj[5]++;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
