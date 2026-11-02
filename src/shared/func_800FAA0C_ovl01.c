/* Shared body (DK-5), from the banked draft of func_800FAA0C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD9CC_ovl01[];
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x7E) == 0x40) {
        func_80016490(2, 0xC, obj);
        func_800FB418_ovl01(0xF, D_800FD9CC_ovl01, obj, 0);
        func_8002A600(0x14, 4, 2);
    }
    if (*(s16*)(obj + 0x7E) < 0x41) {
        obj[0x94] = 1;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        obj[6] = 0;
        if (++obj[0x98] >= 3) {
            obj[5] = 7;
            obj[6] = 2;
            obj[0x94] = 0;
            obj[0x98] = 0;
            *(s16*)(obj + 0x7C) = 0x3C;
            if (D_800D1C0C == 0xC) {
                *(s16*)(obj + 0xE) = -0x30;
            } else {
                *(s16*)(obj + 0xE) = 0xB0;
            }
        }
    }
}
