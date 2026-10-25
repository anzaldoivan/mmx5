/* Shared body (DK-5), from the banked draft of func_800EF0A4_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F8BE8_ovl26[])(u8*);
extern u16 D_800F8BB8_ovl26[][2];
extern signed char D_800D1C26;
extern D_8009A1F8_t D_8009A1F8;

void DEDUP_NAME(u8* arg0) {
    D_8009A1F8_t* d;

    D_800F8BE8_ovl26[*(signed char*)(arg0 + 6)](arg0);
    if (D_800D1C26 == 0 && (*(u16*)(arg0 + 0x14) & 3) == 0) {
        if (++*(s16*)(arg0 + 0x18) >= 0xC) {
            *(s16*)(arg0 + 0x18) = 0;
        }
        d = &D_8009A1F8;
        *(u16*)((u8*)d + 0xB2) = D_800F8BB8_ovl26[*(s16*)(arg0 + 0x18)][0];
        d->unkB6 = D_800F8BB8_ovl26[*(s16*)(arg0 + 0x18)][1];
        d->unkF4 = 1;
    }
}
