/* Shared body (DK-5), from the banked draft of func_800FAF3C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80074EE0[];
extern signed char D_800D1C0C;
extern u8 D_800FD608_ovl01[];
extern void (*D_800FDB88_ovl01[])(u8*);

void DEDUP_NAME(u8* arg0) {
    s32 lim;

    if (*(signed char*)(arg0 + 0x80) == 0) {
        arg0[0x80] = 0x3B;
    }
    *(u8**)(arg0 + 0x58) = D_80074EE0;
    lim = 0x40;
    if (D_800D1C0C != 0xC) {
        lim = 0x120;
    }
    if (lim < *(s16*)(arg0 + 0xE)) {
        *(u8**)(arg0 + 0x68) = D_800FD608_ovl01;
    } else {
        *(u8**)(arg0 + 0x68) = 0;
    }
    D_800FDB88_ovl01[*(signed char*)(arg0 + 6)](arg0);
}
