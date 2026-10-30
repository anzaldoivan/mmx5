/* Shared body (DK-5), from the banked draft of func_800F0FB0_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F103C_ovl05(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_800F0FFC_ovl05(u8* obj);
extern s32 func_8004FD24(u8* a0);

void DEDUP_NAME(u8* obj) {
    func_800F103C_ovl05(obj);
    func_8002DED4(obj);
    if (func_800F0FFC_ovl05(obj) != 0) {
        obj[3] = 0;
        func_8004FD24(obj);
        obj[4] = 2;
    }
}
