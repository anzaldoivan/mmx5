/* Shared body (DK-5), from the banked draft of func_800F1DB4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    obj[0x15] = (*(u8**)(obj + 0x50))[0x15];
    ((s32(*)())set_animation)(obj, 0xD);
    obj[3] = 1;
    obj[4] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
}
