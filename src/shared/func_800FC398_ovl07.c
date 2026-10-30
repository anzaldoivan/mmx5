/* Shared body (DK-5), from the banked draft of func_800FC398_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800FC9E0_ovl07(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_800FC9E0_ovl07(obj);
    func_800171E8(obj, 7);
    obj[6]++;
}
