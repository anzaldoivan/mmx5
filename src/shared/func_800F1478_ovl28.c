/* Shared body (DK-5), from the banked draft of func_800F1478_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void (*D_800FDA78_ovl28[])(u8*);

#define SCR D_1F80004C.bytes
void DEDUP_NAME(u8* a0) {
    D_800FDA78_ovl28[(s8)a0[6]](a0);
    SCR[0x8A] = a0[6];
    SCR[0x8B] = a0[0x7C];
    *(u16*)(SCR + 0x8E) = *(u16*)(a0 + 0xE);
    *(s32*)(SCR + 0x90) = *(s32*)(a0 + 0x24);
    *(s32*)(SCR + 0x94) = *(s32*)(a0 + 0x2C);
}
