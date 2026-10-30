/* Shared body (DK-5), from the banked draft of func_800FA4D8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800F9180_ovl06(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[0x60] = 5;
        func_80017248(obj);
        func_800F9180_ovl06(obj);
    }
}
