/* Shared body (DK-5), from the banked draft of func_800FACAC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800F9180_ovl06(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    D_1F80004C.bytes[0x8B] = 0;
    D_1F80004C.bytes[0x8A] = 0;
    func_800F9180_ovl06(obj);
}
