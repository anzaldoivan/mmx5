/* Shared body (DK-5), from the banked draft of func_800FBE6C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    *(s16*)(obj + 0x7C) = 50;
    obj[6]++;
}
