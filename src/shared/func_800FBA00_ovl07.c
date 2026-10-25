/* Shared body (DK-5), from the banked draft of func_800FBA00_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80091C44;

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (D_80091C44 == 0) {
        func_800171E8(obj, 0);
        D_1F80004C.bytes[0x92] = 0;
        *(s16*)(obj + 0x7C) = 0x50;
        *(s16*)(obj + 0x7E) = 0x17;
        obj[6]++;
    }
}
