/* Shared body (DK-5), from the banked draft of func_800F14AC_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* p) {
    u8* q;
    u8* b;
    u8* c;
    s32 y;
    s32 d;
    u16 e;

    if (p[0x8D] != 0) {
        if (p[0x8D] == 0x21) {
            p[0x93] = 1;
        }
        p[0x8D]--;
        y = *(s16*)(p + 0xE) + 8;
        b = D_8009A0A0;
        d = *(s16*)(b + 0xE) - y;
        if (d >= 0) {
            if (d < 3) {
                *(s32*)(p + 0x24) = 0;
            } else {
                goto cmp; // !FAKE: goto kept for the matching branch layout
            }
        } else if (y - *(s16*)(b + 0xE) >= 3) {
        cmp:
            c = D_8009A0A0;
            if (*(s16*)(c + 0xE) - 8 >= *(s16*)(p + 0xE)) {
                *(s32*)(p + 0x24) = -0x20000;
            } else {
                *(s32*)(p + 0x24) = 0x20000;
            }
        } else {
            *(s32*)(p + 0x24) = 0;
        }
    } else {
        *(s32*)(p + 0x24) = 0;
    }
    if (p[0x8E] != 0) {
        p[0x8E]--;
    } else if (p[0x91] != 0) {
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x21;
            q[1] = 0x17;
            q[2] = 0;
            q[0x15] = func_8002DF78() & 0x40;
            q[0x54] = 0;
            if (p[0x15] == 0) {
                *(s16*)(q + 0xA) = *(s16*)(p + 0xA) + 0x10;
            } else {
                *(s16*)(q + 0xA) = *(s16*)(p + 0xA) - 0x10;
            }
            e = *(u16*)(p + 0xE);
            *(s32*)(q + 0x20) = 0;
            *(s32*)(q + 0x24) = 0;
            q[7] = 1;
            q[0x16] = 7;
            *(s16*)(q + 0xE) = e;
        }
        p[0x8E] = 1;
    }
}
