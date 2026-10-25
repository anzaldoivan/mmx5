/* Shared body (DK-5), from the banked draft of func_800F2568_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80016D54(s32, s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FAC8C_ovl00[];

void DEDUP_NAME(u8* a0) {
    if (--*(s16*)(a0 + 0x7C) == 0) {
        func_80016D54(2, 0xF);
        func_8004D4F4(4, D_800FAC8C_ovl00, a0);
        a0[3] = 0;
        *(s16*)(a0 + 0x7C) = 0x19;
        *(s16*)(a0 + 0x7E) = 5;
        D_1F80004C.bytes[0x87] = 0;
        a0[4] = 6;
    }
}
