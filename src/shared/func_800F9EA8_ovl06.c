/* Shared body (DK-5), from the banked draft of func_800F9EA8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"

extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];

void DEDUP_NAME(u8* arg0) {
    set_animation(arg0, 0xA);
    *(u8**)(arg0 + 0x50) = D_800FF1E4_ovl06;
    *(u8**)(arg0 + 0x54) = D_800FF1E8_ovl06;
    *(s16*)(arg0 + 0x7C) = 1;
    *(s16*)(arg0 + 0x7E) = (random_byte() & 1) + 3;
    arg0[6]++;
}
