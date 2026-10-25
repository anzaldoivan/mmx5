/* Shared body (DK-5), from the banked draft of func_800F85BC_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (func_8002D938(obj, 0x40, 0x40) == 1) {
        obj[4] = 2;
    }
}
