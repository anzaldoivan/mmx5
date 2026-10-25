/* Shared body (DK-5), from the banked draft of func_800FC988_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800FB030_ovl07(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x88] = 0x3C;
        func_800FB030_ovl07(obj);
    }
}
