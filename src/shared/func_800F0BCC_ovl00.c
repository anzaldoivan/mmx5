/* Shared body (DK-5), from the banked draft of func_800F0BCC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800FA870_ovl00[];

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        func_8004FD24(obj);
        func_8004D4F4(1, D_800FA870_ovl00, obj);
        obj[4] = 5;
    }
}
