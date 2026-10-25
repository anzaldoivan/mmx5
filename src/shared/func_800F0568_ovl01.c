/* Shared body (DK-5), from the banked draft of func_800F0568_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FC65C_ovl01[];
extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern void func_80017248(u8* obj);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        *(s16*)(obj + 0x7E) = 2;
    }
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_800FC65C_ovl01, obj);
        obj[4] = 2;
    }
}
