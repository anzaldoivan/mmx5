/* Shared body (DK-5), from the banked draft of func_800F4FDC_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);
extern signed char D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    s32 kind;

    func_80017248(obj);
    kind = ((signed char*)obj)[0x45];
    if (kind == 1) {
        obj[6] = 5;
        if (D_800D1C00[0xC] != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x6A, 0xFF, (u8)D_800D1C00[0x2E]);
            } else if (func_8002DC14() == kind) {
                func_8002385C(0x2F, 0xFF, (u8)D_800D1C00[0x2E]);
            } else {
                func_8002385C(0x61, 0xFF, (u8)D_800D1C00[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
    }
}
