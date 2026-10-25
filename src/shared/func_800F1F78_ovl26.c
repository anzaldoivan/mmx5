/* Shared body (DK-5), from the banked draft of func_800F1F78_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern s16 D_800F961C_ovl26[];

void DEDUP_NAME(u8* arg0) {
    u8* a = D_8009A0A0;
    u8* b = D_8009A1F8;

    *(s16*)(b + 0xE) = *(u16*)(a + 0xE) - 0x1E;
    if (*(s16*)(b + 0xE) >= D_800F961C_ovl26[(s8)arg0[2]]) {
        *(s16*)(b + 0xE) = D_800F961C_ovl26[(s8)arg0[2]];
    }
    if (*(s16*)(b + 0xE) <= 0) {
        *(s16*)(b + 0xE) = 0;
    }
    if (*(s8*)(a + 5) != 0) {
        if ((s8)arg0[2] == 1) {
            arg0[4] = 3;
            return;
        }
        arg0[4]++;
    }
}
