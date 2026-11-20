#include "types.h"

extern u8 D_8009A1F8[];

void func_800F7194_ovl09(u8* arg0) {
    u8* p = D_8009A1F8;
    u8* q;
    u8* r;
    s32 d;
    s32 acc;
    s32 n;
    s32 m;

    if (*(s32*)(p + 0x14) != *(s32*)(p + 0x8)) {
        d = *(u16*)(p + 0xA) - *(u16*)(p + 0x16);
        *(s16*)(arg0 + 0x16) = d;
        if ((s16)d >= 0) {
            if ((s16)d >= 8) {
                *(s16*)(arg0 + 0x16) = 8;
            }
        } else if ((s16)d < -8) {
            *(s16*)(arg0 + 0x16) = -8;
        }
        acc = arg0[0x15] + arg0[0x16];
        arg0[0x15] = acc;
        if ((s8)acc >= 0) {
            if ((s8)acc >= 8) {
                n = arg0[0x14] - 1;
                arg0[0x14] = n;
                if ((s8)n < 0) {
                    arg0[0x14] = 2;
                }
                goto shared; // !FAKE: goto kept for the matching branch layout
            }
        } else if ((s8)acc < -7) {
            n = arg0[0x14] + 1;
            arg0[0x14] = n;
            if ((s8)n >= 3) {
                arg0[0x14] = 0;
            }
        shared: // !FAKE: label kept for the matching branch layout
            q = D_8009A1F8;
            m = ((s8*)arg0)[0x14];
            q[0xA0] = 1;
            *(s16*)(q + 0x5E) = m << 9;
            arg0[0x15] = 0;
        }
        r = D_8009A1F8;
        *(s16*)(r + 0x62) = *(u16*)(r + 0xE) - 0x160;
    }
}
