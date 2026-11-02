#include "types.h"

extern s32 func_800EFAF8_ovl24(u8* arg0, s8 arg1);
extern void func_800F0CC0_ovl24(u8* arg0, u8 arg1, s8 arg2, s32 arg3, s32 arg4);
extern s8 D_800D1C28;
extern u16 D_800F4E80_ovl24;
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;
extern s16 D_800F5F78_ovl24;
extern s8 D_800F5F7B_ovl24;
extern s8 D_800F5F7C_ovl24;
extern s8 D_800F5F7D_ovl24;
extern s8 D_800F5F7E_ovl24;

void func_800EF3BC_ovl24(u8* arg0) {
    while (D_800F5F7B_ovl24 < 0x20) {
        if (func_800EFAF8_ovl24(arg0, D_800F5F7B_ovl24) != 0) {
            if (D_800F5F7C_ovl24 == 0) {
                func_800F0CC0_ovl24(arg0, 0x94, 1, 0xA0, 0x74);
            }
            D_800F5F7C_ovl24 = 1;
            func_800F0CC0_ovl24(arg0, D_800F5F7B_ovl24 - 0x6B,
                                D_800F5F7D_ovl24 * 2 + 4, 0xA0,
                                D_800F5F7D_ovl24 * 0x10 + 0x88);
            func_800F0CC0_ovl24(arg0, D_800F5F7B_ovl24 - 0x4B,
                                D_800F5F7D_ovl24 * 2 + 3, 0x18,
                                D_800F5F7D_ovl24 * 0x10 + 0x88);
            if (++D_800F5F7D_ovl24 == 3) {
                D_800F5F7B_ovl24++;
                break;
            }
        }
        D_800F5F7B_ovl24++;
    }
    if (D_800F5F7B_ovl24 >= 0x20 && D_800F5F7E_ovl24 != 0 &&
        D_800F5F7D_ovl24 < 3) {
        if (D_800F5F7C_ovl24 == 0) {
            func_800F0CC0_ovl24(arg0, 0x94, 1, 0xA0, 0x74);
        }
        D_800F5F7C_ovl24 = 1;
        func_800F0CC0_ovl24(arg0, D_800F5F7E_ovl24 - 0x2C,
                            D_800F5F7D_ovl24 * 2 + 4, 0xA0,
                            D_800F5F7D_ovl24 * 0x10 + 0x88);
        func_800F0CC0_ovl24(arg0, D_800F5F7E_ovl24 - 0x29,
                            D_800F5F7D_ovl24 * 2 + 3, 0x18,
                            D_800F5F7D_ovl24 * 0x10 + 0x88);
        D_800F5F7E_ovl24 = 0;
        D_800F5F7D_ovl24++;
    }
    if (D_800F5F7D_ovl24 != 0) {
        D_800F5F76_ovl24 = 0;
        D_800D1C28 = 1;
        D_800F5F78_ovl24 = D_800F5F7D_ovl24 * 2 + 2;
        D_800F5F74_ovl24 = D_800F4E80_ovl24;
        arg0[2] = arg0[2] + 1;
    } else {
        arg0[2] = 3;
    }
}
