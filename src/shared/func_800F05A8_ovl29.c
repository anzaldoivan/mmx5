/* Shared body (DK-5), from the banked draft of func_800F05A8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F0978_ovl29(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_800F0978_ovl29(obj);
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -0x1CCCC;
    } else {
        *(s32*)(obj + 0x20) = 0x1CCCC;
    }
    func_800171E8(obj, 0);
    obj[6] = 1;
}
