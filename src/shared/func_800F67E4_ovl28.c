/* Shared body (DK-5), from the banked draft of func_800F67E4_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248();
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_80017248();
    func_800171E8(obj, 1);
    obj[6]++;
}
