/* Shared body (DK-5), from the banked draft of func_800F5AB4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 rsin(s32);
extern s32 func_8002DF78(void);

// from rockx5 800F5AB4: advance the scratchpad state's phase by a random step, set y from its sine
void DEDUP_NAME(u8* e) {
    s32 t;
    s32 r;

    t = rsin(D_1F80004C.scr5308->unk84) << 7;
    r = (func_8002DF78() & 0x1F) + 0x10;
    D_1F80004C.scr5308->unk84 += r;
    D_1F80004C.scr5308->unk84 &= 0xFFF;
    *(s32*)(e + 0xC) = D_1F80004C.scr5308->unk80 + t;
}
