/* Shared body (DK-5), from the banked draft of func_800F0F98_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    if (D_80091C44 == 0) {
        func_800171E8(obj, 12);
        obj[5]++;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
