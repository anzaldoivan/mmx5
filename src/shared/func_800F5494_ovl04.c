/* Shared body (DK-5), from the banked draft of func_800F5494_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern void (*D_80101BD0_ovl04[])(u8*);

void DEDUP_NAME(u8* arg0) {
    u8* g = D_8009A0A0;

    if (((signed char*)g)[0xF3] == 0) {
        D_80101BD0_ovl04[((signed char*)arg0)[6]](arg0);
    } else if ((u8)(g[0xFA] - 2) >= 2) {
        D_80101BD0_ovl04[((signed char*)arg0)[6]](arg0);
    }
}
