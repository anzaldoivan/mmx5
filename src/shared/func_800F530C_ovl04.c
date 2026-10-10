/* Shared body (DK-5), from the banked draft of func_800F530C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_8002DF54(obj);
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6]++;
    }
}
