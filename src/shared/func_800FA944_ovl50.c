/* Shared body (DK-5), from the banked draft of func_800FA944_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 func_80016490(s32, s32,
                         void*); // s32 keeps the post-call temp in v1 (C0069)

void DEDUP_NAME(Actor50* arg0) {
    func_8002385C(0x2B, 0xFF, 0);
    func_80016490(2, 0x4F, 0);
    arg0->step++;
}
