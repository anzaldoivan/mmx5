/* Shared body (DK-5), from the banked draft of func_800F5364_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 4);
    *(s16*)(obj + 0x7C) = (func_8002DF78() & 3) * 10 + 0x20;
    obj[6]++;
}
