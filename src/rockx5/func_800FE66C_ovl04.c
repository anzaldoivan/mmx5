#include "types.h"

extern s32 func_80028B18(s32, s32, s32, void*);
extern s32 func_80024548(s32);
extern signed char D_8009A0A5;
extern u8 D_800D1C00[];
extern u8 D_80102A50_ovl04[];

void func_800FE66C_ovl04(u8* arg0) {
    u8* g;

    if (D_8009A0A5 == 0x14) {
        g = D_800D1C00;
        g[0x24] = 1;
        g[0x25] = 0;
        *(u8**)(g + 0x20) = arg0;
        arg0[0x5C] = 0;
        if (((s8*)arg0)[2] == 1) {
            g[0xA2] = 0x7F;
        } else if (((s8*)arg0)[2] == 9) {
            func_80028B18(0, 0xBA0, 0x3A0, D_80102A50_ovl04);
            g[0xA2] = 0x7F;
        } else {
            g[0xA2] = 0x7F;
        }
        func_80024548(0);
        *(s16*)(arg0 + 0x7C) = 2;
        arg0[5]++;
    }
}
