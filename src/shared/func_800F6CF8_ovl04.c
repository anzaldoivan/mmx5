/* Shared body (DK-5), from the banked draft of func_800F6CF8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* a0);

void DEDUP_NAME(u8* a0) {
    func_8002DF54(a0);
    func_80017248(a0);
    if (*(s16*)(a0 + 0xE) < 0x11) {
        a0[0x8F] = 0x1E;
        a0[0x6] = 2;
    }
}
