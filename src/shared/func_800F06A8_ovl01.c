/* Shared body (DK-5), from the banked draft of func_800F06A8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (obj[0x70] & 2) {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x20000;
        obj[0x6] = 2;
    }
}
