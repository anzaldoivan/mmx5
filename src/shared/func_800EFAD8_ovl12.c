/* Shared body (DK-5), from the banked draft of func_800EFAD8_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern signed char D_8009A0A5;
extern u8 D_8009A23F;

void DEDUP_NAME(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        D_8009A23F = 2;
        func_8003D29C(0x1D, 0x40);
        a->unk7C = 0x28;
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk6++;
    }
}
