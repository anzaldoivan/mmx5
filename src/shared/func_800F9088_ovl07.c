/* Shared body (DK-5), from the banked draft of func_800F9088_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern Gm1C00 D_800D1C00;
extern void func_800F94C8_ovl07(s32);
extern void func_80016490(s32, s32, void*);

void DEDUP_NAME(u8* obj, u8 a1, u8 a2) {
    u8 hi;
    s8 i;
    s8 v;
    u8* q;

    hi = D_8009A0A0[0x5C] & 0x80;
    if ((D_8009A0A0[0x5C] & 0x7F) < (s8)D_800D1C00.lim[(s8)D_8009A0A0[2]]) {
        func_800F94C8_ovl07(1);
        obj[0x85] = 4;
        obj[0x84] = a1;
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[0] |= 8;
    } else {
        obj[4] = 3;
    }
    if (!((D_8009A0A0[0x5C] & 0x7F) < (s8)D_800D1C00.lim[(s8)D_8009A0A0[2]])) {
        D_8009A0A0[0x5C] = D_800D1C00.lim[(s8)D_8009A0A0[2]] | hi;
    }
    for (i = 0; i < 2; i++) {
        q = &D_800D1C00.cnt[i];
        if (D_800D1C00.flags & (0x1000 << i)) {
            v = *q & 0x7F;
            if (v < 0x20) {
                v = a2 + v;
                if (v >= 0x20) {
                    v = 0x20;
                    func_80016490(0, 0x18, 0);
                }
                *q = v | 0x80;
                return;
            }
        }
    }
}
