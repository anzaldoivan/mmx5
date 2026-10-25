/* Shared body (DK-5), from the banked draft of func_800FA458_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* DEDUP_CALLEE(void);
extern u8 D_80091C44;
extern u8* D_800FBC88_ovl50;
extern u8 D_8009A1F8[];

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8* q;

    if (D_80091C44 == 0) {
        p = DEDUP_CALLEE();
        D_800FBC88_ovl50 = p;
        if (p != 0) {
            p[0] = 1;
            D_800FBC88_ovl50[1] = 10;
            D_800FBC88_ovl50[0x36] = 0x22;
            D_800FBC88_ovl50[2] = 0;
        }
        q = D_8009A1F8;
        *(s32*)(q + 0x5C) = 0;
        *(s32*)(q + 0x60) = 0x800000;
        q[0xA0] = 1;
        q[0x57] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
