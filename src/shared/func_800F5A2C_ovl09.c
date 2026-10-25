/* Shared body (DK-5), from the banked draft of func_800F5A2C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 3);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x28;
    obj[6]++;
    func_80017248(obj);
    func_8002DED4(obj);
}
