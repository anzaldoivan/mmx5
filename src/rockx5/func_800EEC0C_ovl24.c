#include "types.h"

extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);
extern u8 D_8009A169;
extern u8 D_800D1C00[];
extern s16 D_800F5F78_ovl24;

void func_800EEC0C_ovl24(u8* arg0) {
    s32 t;
    s32 sh;

    switch ((s8)D_800D1C00[0x27]) {
    case 0:
        func_800F0C00_ovl24((s32)arg0, 0, 1);
        if ((s8)D_800D1C00[0x26] == 0) {
            D_800F5F78_ovl24 = 7;
            break;
        }
        t = (u8)(D_800D1C00[0x26] - 1);
        t = (u32)t < 8;
        if (t) {
            sh = (s8)D_800D1C00[0x26] - 1;
            if ((D_8009A169 >> sh) & 1) {
                D_800F5F78_ovl24 = 7;
                break;
            }
            arg0[0x4C] |= 1 << sh;
            func_800F0C00_ovl24((s32)arg0, 5, 8);
            func_800F0C00_ovl24((s32)arg0, 0x8D, 9);
            D_800F5F78_ovl24 = 9;
        } else {
            func_800F0C00_ovl24((s32)arg0, 5, 8);
            func_800F0C00_ovl24((s32)arg0, 0x8D, 9);
            D_800F5F78_ovl24 = 9;
        }
        break;
    case 1:
        if ((u8)(D_800D1C00[0x26] - 9) < 2) {
            t = arg0[0xCA] - 0x14;
            arg0[0xCA] = t;
        }
        func_800F0C00_ovl24((s32)arg0, 1, 1);
        D_800F5F78_ovl24 = 7;
        break;
    case 2:
        func_800F0C00_ovl24((s32)arg0, 0x16, 1);
        D_800F5F78_ovl24 = 7;
        break;
    }
    func_800F0C00_ovl24((s32)arg0, 0x1D, 1);
    func_800F0C00_ovl24((s32)arg0, 2, 2);
    func_800F0C00_ovl24((s32)arg0, 3, 4);
    func_800F0C00_ovl24((s32)arg0, 4, 6);
    func_800F0C00_ovl24((s32)arg0, 0x8A, 3);
    func_800F0C00_ovl24((s32)arg0, 0x8B, 5);
    func_800F0C00_ovl24((s32)arg0, 0x8C, 7);
    if (D_800D1C00[0x26] < 0xB) {
        if (arg0[0x79] < 5) {
            func_800F0C00_ovl24((s32)arg0, 0xDD, 1);
        }
    }
    D_800D1C00[0x28] = 1;
    arg0[2]++;
}
