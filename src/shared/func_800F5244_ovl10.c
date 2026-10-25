/* Shared body (DK-5), from the banked draft of func_800F5244_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[0x61] = 0;
        func_800171E8(obj, 0);
        *(s16*)(obj + 0x7C) = 0x14;
        obj[6] = 6;
    }
}
