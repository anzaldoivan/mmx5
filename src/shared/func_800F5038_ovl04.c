/* Shared body (DK-5), from the banked draft of func_800F5038_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    u8* d;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        d = D_800D1C00;
        if (*(s8*)(d + 0xC) != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x2E, 0xFF, *(s8*)(d + 0x2E));
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x60, 0xFF, *(s8*)(d + 0x2E));
            } else {
                func_8002385C(0x60, 0xFF, *(s8*)(d + 0x2E));
            }
            D_800D1C00[0x2E] = 1;
        }
        obj[5]++;
    }
}
