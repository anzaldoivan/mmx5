/* Shared body (DK-5), from the banked draft of func_800F6FE0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_8009A16A;
extern void* D_800FBFCC_ovl10[];

void DEDUP_NAME(u8* arg0) {
    u8* obj;
    u8 kind;
    s8 st;

    arg0[0x62] = 3;
    obj = *(u8**)(arg0 + 0x7C);
    ((void (*)(u8*))D_800FBFCC_ovl10[(s8)arg0[5]])(arg0);
    kind = obj[0x47];
    if (kind == 0x76 || kind == 0x7F) {
        arg0[3] = 1;
    } else {
        arg0[3] = 0;
    }
    if (((s8*)obj)[4] == 2 || (st = ((s8*)obj)[5]) == 2 ||
        (st == 6 && ((s8*)obj)[6] < 3)) {
        if (((s8*)arg0)[5] != 0) {
            D_8009A16A = 0;
        }
        arg0[4] = 2;
    }
}
