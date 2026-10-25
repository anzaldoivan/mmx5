/* Shared body (DK-5), from the banked draft of func_800F9FCC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800FB308_ovl01(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        func_800171E8(obj, 0);
        func_800FB308_ovl01(obj);
        obj[5] = 3;
        obj[6] = 0;
    }
}
