/* Shared body (DK-5), from the banked draft of func_800F5C40_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F5C70_ovl18(s32 arg0);
extern void func_8002D6FC(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800F5C70_ovl18(0);
    func_8002D6FC(obj);
}
