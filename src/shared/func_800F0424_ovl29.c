/* Shared body (DK-5), from the banked draft of func_800F0424_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F0978_ovl29(u8* obj);
extern void func_800F017C_ovl29(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_800F0978_ovl29(obj);
    func_800F017C_ovl29(obj);
    if (obj[0x80] == 0) {
        func_800171E8(obj, obj[0x88] + 0x12);
    } else {
        func_800171E8(obj, obj[0x88] + 0x17);
    }
    obj[6] = 1;
}
