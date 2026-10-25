/* Shared body (DK-5), from the banked draft of func_800F5808_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F6250_ovl10(void*);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_800F6250_ovl10(obj);
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6] = 2;
    }
}
