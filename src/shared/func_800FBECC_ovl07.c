/* Shared body (DK-5), from the banked draft of func_800FBECC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800FC9E0_ovl07(u8* obj);
extern void func_800FB030_ovl07(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (*(u16*)(obj + 0x7C) & 0x1F) {
        func_800FC9E0_ovl07(obj);
    }
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x92] = 0;
        func_800FB030_ovl07(obj);
    }
}
