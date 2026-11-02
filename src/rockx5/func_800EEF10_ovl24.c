#include "types.h"

extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);
extern u8 D_80091C44;
extern u8 D_8009A427;
extern u8 D_800D1C28;
extern u8 D_800F5F80_ovl24;

void func_800EEF10_ovl24(u8* arg0) {
    u8 state;

    if (D_80091C44 == 0) {
        D_800D1C28 = 1;
        D_8009A427 = 0;
        state = arg0[0xC0];
        if (state < 4) {
            D_800F5F80_ovl24 = 0;
            func_800F0C00_ovl24((s32)arg0, 0x1E, 1);
        } else if (state < 8) {
            D_800F5F80_ovl24 = 1;
            func_800F0C00_ovl24((s32)arg0, 0x13, 1);
            func_800F0C00_ovl24((s32)arg0, 0x8E, 1);
            func_800F0C00_ovl24((s32)arg0, 0x14, 1);
            func_800F0C00_ovl24((s32)arg0, 0x15, 1);
        } else {
            D_800F5F80_ovl24 = 2;
            func_800F0C00_ovl24((s32)arg0, 0x13, 1);
            func_800F0C00_ovl24((s32)arg0, 0x8E, 1);
            func_800F0C00_ovl24((s32)arg0, 0x1F, 1);
            func_800F0C00_ovl24((s32)arg0, 0x20, 1);
        }
        arg0[2]++;
    }
}
