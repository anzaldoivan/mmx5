#include "types.h"

extern u8 D_800D1C00[];
extern s32 D_800F4ED0_ovl24[][2];
extern s8 D_800F5F7F_ovl24;

s32 func_800EFAF8_ovl24(u8* arg0, s8 arg1) {
    s32 i;
    s32 b;
    s32* slot;
    s32 t;
    s32 lim;
    u8* g;

    i = arg1 << 2;
    b = (s32)arg0 + 0x114;
    slot = (s32*)(b + i);
    t = *slot;
    if (t == 0) {
        return 0;
    }
    g = D_800D1C00;
    lim = *(s32*)(g + 0xB0) + 0x34BC0;
    if (lim >= t) {
        *slot = 0;
        if ((u8)arg1 < 0x10) {
            s32 old = *(s32*)(arg0 + 0x80);
            s32 bit = D_800F4ED0_ovl24[arg1][1];
            if (!(old & bit)) {
                *(s32*)(arg0 + 0x80) = old | bit;
                if ((u8)arg1 < 8) {
                    if (D_800F5F7F_ovl24 == 0) {
                        g[0x47] += 2;
                    } else {
                        g[0x48] += 2;
                    }
                } else if (D_800F5F7F_ovl24 == 0) {
                    g[0x53] += 2;
                } else {
                    g[0x54] += 2;
                }
            }
        } else if ((u32)(arg1 - 0x10) < 0x10) {
            *(s32*)(arg0 + 0x84) |= D_800F4ED0_ovl24[arg1][1];
        }
        return 1;
    }
    *slot = t - lim;
    return 0;
}
