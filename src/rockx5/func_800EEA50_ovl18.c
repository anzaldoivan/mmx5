#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern void func_800EED68_ovl18(u8* arg0);
extern u8 D_8009A1F8[];
extern u8 D_8009A24C[];
extern s8 D_800D1C00[];
extern u8 D_800F6CCC_ovl18[];

void func_800EEA50_ovl18(u8* arg0) {
    if ((u8)((u8)D_800D1C00[0x1D] - 2) < 8) {
        D_8009A24C[3] = 0;
    }
    if (D_800D1C00[0x1D] == 1 || (u8)((u8)D_800D1C00[0x1D] - 0xB) < 8) {
        func_80028B18(0, 0xD30, 0x590, D_800F6CCC_ovl18);
        *(s16*)(arg0 + 0x1A) = 1;
        arg0[0x1C] = 2;
    } else {
        *(s16*)(arg0 + 0x1A) = 0;
        arg0[0x1C] = 0;
    }
    if (D_800D1C00[0x1D] >= 0x15) {
        D_8009A1F8[0x58] = 2;
        *(s16*)(D_8009A1F8 + 0x94) = -0x7EE;
        *(s16*)(D_8009A1F8 + 0x96) = -0x150;
        D_8009A1F8[0xAC] = 1;
        *(s16*)(D_8009A1F8 + 0xE8) = 0xA90;
        *(s16*)(D_8009A1F8 + 0xEA) = 0x590;
        D_8009A1F8[0xA0] = 1;
        D_8009A1F8[0xF4] = 1;
        arg0[5] = 1;
        arg0[6] = 0;
        arg0[4]++;
        func_800EED68_ovl18(arg0);
        return;
    }
    arg0[5] = 0;
    arg0[6] = 0;
    *(s16*)(arg0 + 0x14) = 0;
    *(s16*)(arg0 + 0x18) = 0;
    arg0[4]++;
    func_800EED68_ovl18(arg0);
}
