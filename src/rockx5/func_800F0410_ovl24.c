#include "types.h"

extern s8 D_800F5F7D_ovl24;
extern u16 D_800C9320;
extern s8 D_800F5F7B_ovl24;
extern u8 D_800D1C28;
extern s8 D_800F5F7E_ovl24;

void func_800F0410_ovl24(u8* arg0) {
    if (D_800F5F7D_ovl24 != 0) {
        if (!(D_800C9320 & 0x8FF)) {
            return;
        }
        if (D_800F5F7B_ovl24 < 0x20 || D_800F5F7E_ovl24 != 0) {
            D_800D1C28 = 0x40;
            D_800F5F7D_ovl24 = 0;
            arg0[2] = 1;
            return;
        }
    }
    D_800D1C28 = 0x7F;
    arg0[2]++;
}
