/* Shared body (DK-5), from the banked draft of func_800F0280_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248();
extern void func_8002DF54(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248();
    *(s32*)(obj + 0x24) = 0x60000;
    func_8002DF54(obj);
}
