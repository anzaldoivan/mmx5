#include "types.h"

extern u8 D_800D1C00[];

s32 func_80031670(u8* a0, s8 dmg) {
    s16 t;
    u8 k;

    if (dmg == 0) {
        return 0;
    }
    if (dmg < 0) {
        if (*(s32*)(a0 + 0xFC) & 0x80) {
            dmg = dmg / 2;
        }
        if (dmg == 0) {
            dmg = -1;
        }
    } else {
        if (dmg == 0x7F) {
            return 0x7F;
        }
        if (D_800D1C00[0xA0] == 0) {
            dmg = dmg * 3 / 4;
        } else if (D_800D1C00[0xA0] >= 2) {
            t = (s8)(dmg / 4) + dmg;
            if (t >= 0x80) {
                t = 0x7F;
            }
            dmg = t;
        }
        k = a0[0xFA];
        if (k == 1 || k == 3 || k == 2 || k == 4 ||
            (k == 5 && (D_800D1C00[0x4A] & 0x10)) ||
            (*(s32*)(a0 + 0xFC) & 0x20000)) {
            dmg = dmg >> 2; // halfdmg: was dmg / 2 (dmg >= 0 here, so == dmg / 4)
        }
        if (dmg == 0) {
            dmg = 1;
        }
    }
    return dmg;
}
