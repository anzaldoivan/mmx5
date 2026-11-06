#include "types.h"

extern s8 D_800F4FD0_ovl24[][5];
extern s8 D_800D1C00[];

void func_800EEB30_ovl24(void) {
    s32 i = 0;

    if (D_800F4FD0_ovl24[D_800D1C00[0x26] - 1][0] == 0) {
        for (; i < 4; i++) {
            D_800D1C00[0xC2 + i] +=
                D_800F4FD0_ovl24[D_800D1C00[0x26] - 1][i + 1];
        }
    } else {
        for (; i < 4; i++) {
            D_800D1C00[0xC6 + i] +=
                D_800F4FD0_ovl24[D_800D1C00[0x26] - 1][i + 1];
        }
    }
}
