/* Shared body (DK-5), from the banked draft of func_800F9B2C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800FAEF8_ovl06(u8* obj);
extern void func_800F9180_ovl06(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if ((*(u16*)(obj + 0x7C) & 0x1F) == 0) {
        func_800FAEF8_ovl06(obj);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800F9180_ovl06(obj);
    }
}
