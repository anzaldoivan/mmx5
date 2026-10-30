/* Shared body (DK-5), from the banked draft of func_800EF5C8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* o) {
    func_800171E8(o, 2);
    func_80017248(o);
    *(s32*)(o + 0x20) = 0;
    o[6] = 1;
}
