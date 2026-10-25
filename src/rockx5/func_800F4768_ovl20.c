#include "types.h"

extern u8 D_800D1C00[];
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F4768_ovl20(u8* a0) {
    if ((u32)(D_800D1C00[1] - 8) < 2) {
        a0[3] = 0;
        return;
    }
    if (((s8*)a0)[2] == 0) {
        if (D_800D1C00[0xCB] & 1) {
            func_80017214(a0, 0, 1);
        } else {
            func_80017214(a0, 0, 0);
        }
    } else {
        if (D_800D1C00[0xCB] & 1) {
            func_80017214(a0, 1, 1);
        } else {
            func_80017214(a0, 1, 0);
        }
    }
    func_8002D9EC(a0, 0x80, 0x40);
}
