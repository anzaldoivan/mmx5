#include "types.h"

extern void func_800F0C58_ovl24(u8* a0, s32 a1, s32 a2, s32 a3);
extern u8 D_8009A169;
extern u8 D_800D1C00[];
extern u16 D_800F4E74_ovl24;
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;
extern s16 D_800F5F78_ovl24;

void func_800EF14C_ovl24(u8* arg0) {
    u8* p = D_800D1C00;

    p[0x28] = 1;
    if (p[0xA1] != p[0xCC]) {
        func_800F0C58_ovl24(arg0, 0x8F, 1, 0);
        func_800F0C58_ovl24(arg0, 0x91, 2, 0);
        func_800F0C58_ovl24(arg0, 0x90, 3, 0);
        D_800F5F78_ovl24 = 3;
        if (((s8*)p)[0x27] == 0) {
            if (!((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
                func_800F0C58_ovl24(arg0, 0x93, 4, 0);
                func_800F0C58_ovl24(arg0, 0x92, 5, 0);
                D_800F5F78_ovl24 = 5;
            }
        }
    } else if (((s8*)p)[0x27] == 0 &&
               !((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
        func_800F0C58_ovl24(arg0, 0x8F, 1, 0);
        func_800F0C58_ovl24(arg0, 0x93, 2, -0x10);
        func_800F0C58_ovl24(arg0, 0x92, 3, -0x10);
        D_800F5F78_ovl24 = 3;
    } else {
        arg0[1] = 3;
        arg0[2] = 0;
        return;
    }
    D_800F5F76_ovl24 = 0;
    D_800F5F74_ovl24 = D_800F4E74_ovl24;
    arg0[2]++;
}
