/* Shared body (DK-5), from the banked draft of func_800F7354_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D89C(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D6FC(u8* obj);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* obj) {
    *(u16*)(obj + 0x42) = *(u16*)(*(u8**)(obj + 0x7C) + 0x42);
    obj[0x15] = D_8009A0A0[0x15];
    if ((u8)(obj[0x47] + 0x56) < 2) {
        obj[0x16] = 5;
    } else {
        obj[0x16] = 2;
    }
    func_80017248(obj);
    func_8002D89C(obj);
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        s8* g = (s8*)D_8009A0A0;
        obj[4] = 0x10;
        if (g[2] != 0) {
            func_800171E8(obj, 0x1F);
        } else {
            func_800171E8(obj, 0x1D);
        }
    }
    if (D_8009A0A0[0x5C] == 0x80) {
        func_8002D6FC(obj);
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 3) {
        func_8002D6FC(obj);
    }
}
