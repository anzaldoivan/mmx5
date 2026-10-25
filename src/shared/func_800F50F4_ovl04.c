/* Shared body (DK-5), from the banked draft of func_800F50F4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern void func_80017248(u8* obj);
extern void func_80044DD0(s32 a0);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (D_80091C44 == 0) {
        obj[5]++;
        obj[6] = 0;
        *(s16*)(obj + 0x7C) = 3;
        func_80044DD0(4);
        func_800171E8(obj, 2);
    }
}
