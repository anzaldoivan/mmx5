/* Shared body (DK-5), from the banked draft of func_800F0BCC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FA870_ovl00[];

void DEDUP_NAME(u8* obj) {
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        func_8004FD24(obj);
        func_8004D4F4(1, D_800FA870_ovl00, obj);
        obj[4] = 5;
    }
}
