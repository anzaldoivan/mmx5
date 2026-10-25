/* Shared body (DK-5), from the banked draft of func_8002979C by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A1F8[];

void DEDUP_NAME(s16* p) {
    s16 t;
    s16 a;
    s16 d;

    t = D_8009A1F8[5] >> 1;
    t = t + D_8009A1F8[5];
    a = t + p[0x20];
    p[5] = a;
    d = a - p[0xB];
    t = D_8009A1F8[7] >> 1;
    t = t + D_8009A1F8[7];
    p[7] = t + p[0x21];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] + 0x10;
            } else {
                p[5] = a - 0x140;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] - 0x10;
            } else {
                p[5] = a + 0x140;
            }
        }
    }
    d = p[7] - p[0xD];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] - 0x140;
            } else {
                p[7] = p[0xD] + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] + 0x140;
            } else {
                p[7] = p[0xD] - 0x10;
            }
        }
    }
}
