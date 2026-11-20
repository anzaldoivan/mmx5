/* Shared body (DK-5), from the banked draft of func_800F5808_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void func_800F6250_ovl10(void*);

void DEDUP_NAME(u8* obj) {
    func_800F6250_ovl10(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6] = 2;
    }
}
