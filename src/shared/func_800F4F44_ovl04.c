/* Shared body (DK-5), from the banked draft of func_800F4F44_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern signed char D_8009A0A5;
extern u8 D_8009A23F;
extern signed char D_800D1C0C;

void DEDUP_NAME(Ent8EF0* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        D_8009A23F = 2;
        if (D_800D1C0C != 0xC) {
            func_8003D29C(0x1D, 0x40);
        }
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk7C = 0x168;
        a->unk5++;
    }
}
