/* Shared body (DK-5), from the banked draft of func_800FA520_ovl52 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32, s32, void*);
extern u8 D_80091C44;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern s32 D_8009A420;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void DEDUP_NAME(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        DEDUP_CALLEE(2, 0x6C, 0);
        if (!(D_8009A420 & 1)) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
        if (D_800D50DE >= 0x1F) {
            p = D_8009A1F8;
            p[0x3] = 0;
            p[0x4C] = 1;
            p[0x57] = 0;
            p[0xA0] = 1;
            p[0xAB] = 1;
            *(s16*)(p + 0xB2) = 0;
            *(s16*)(p + 0xB6) = 0x400;
            p[0xF4] = 1;
            arg0[1]++;
        }
    }
}
