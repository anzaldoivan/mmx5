/* Shared body (DK-5), from the banked draft of func_800F5298_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s16 D_8009A0AE;

void DEDUP_NAME(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0xE) = D_8009A0AE;
        *(u8*)(obj + 0x15) = 0x40;
        *(u8*)(obj + 0x6) += 1;
        *(s32*)(obj + 0x20) = 0x20000;
        *(s16*)(obj + 0x7C) = 0x50;
    }
}
