/* Shared body (DK-5), from the banked draft of func_800EFA9C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 4);
    func_80017248(obj);
    *(s32*)(obj + 0x80) = 0;
    *(s32*)(obj + 0x84) = 0;
    *(s32*)(obj + 0x88) = 1;
    *(s32*)(obj + 0x8C) = 0;
    obj[6] = 1;
}
