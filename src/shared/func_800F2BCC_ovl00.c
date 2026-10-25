/* Shared body (DK-5), from the banked draft of func_800F2BCC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800F2EA4_ovl00(u8* obj, s32 arg);
extern void func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    if ((s8)obj[0x45] == 1) {
        func_800F2EA4_ovl00(obj, 0);
        func_800171E8(obj, 8);
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A] = 0;
        obj[5] = 2;
        obj[6] = 0;
    }
}
