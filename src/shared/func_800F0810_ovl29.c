/* Shared body (DK-5), from the banked draft of func_800F0810_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* self) {
    *(s32*)(self + 0x20) = 0;
    *(s32*)(self + 0x28) = 0;
    *(s32*)(self + 0x24) = 0;
    *(s32*)(self + 0x2C) = 0;
    DEDUP_CALLEE(self, 0x14);
    self[6]++;
}
