/* Shared body (DK-5), from the banked draft of func_800FADE4_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_800171E8(obj, 0xC);
        obj[6] = 5;
    }
}
