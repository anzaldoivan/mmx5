/* Shared body (DK-5), from the banked draft of func_800F6DF0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8002DC14(void);
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if ((s8)obj[0x45] == 2) {
        obj[0x15] = 0;
        obj[6]++;
        if ((s8)D_800D1C00[0xC] != 12) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x6C, 0xFF, D_800D1C00[0x2E]);
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x32, 0xFF, D_800D1C00[0x2E]);
            } else {
                func_8002385C(0x64, 0xFF, D_800D1C00[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
    }
}
