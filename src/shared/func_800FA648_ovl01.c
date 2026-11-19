/* Shared body (DK-5), from the banked draft of func_800FA648_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern signed char D_800D1C0C;
extern u8 D_800FD60C_ovl01[];

void DEDUP_NAME(u8* obj) {
    s32 limit = 0x40;

    if (D_800D1C0C != 12) {
        limit = 0x120;
    }
    animate_object(obj);
    apply_object_motion(obj);
    if (limit < *(s16*)(obj + 0xE)) {
        *(u8**)(obj + 0x68) = D_800FD60C_ovl01;
        obj[6] = 4;
    }
}
