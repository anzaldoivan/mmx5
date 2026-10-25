/* Shared body (DK-5), from the banked draft of func_800F7FE0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800F81F4_ovl11(u8* obj);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    obj[0x60] = 4;
    obj[0x62] = 0;
    func_800171E8(obj, 0);
    func_800F81F4_ovl11(obj);
    func_80017248(obj);
    *(s16*)(obj + 0x7C) = 0x3C;
    obj[6]++;
}
