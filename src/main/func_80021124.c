#include "types.h"

void func_80021124(u8* a0) {
    s32 i;
    u8* q;
    s32 t;

    for (i = 0; i < 16; i++) {
        u8* b = a0 + 0x194;

        if (b[i] == ((s8*)a0)[0x1D]) {
            break;
        }
    }
    if (i == 16) {
        goto fail; // !FAKE: goto kept for the matching branch layout
    }
    t = i + (s32)a0;
    q = (u8*)t + 0x195;
    t = 0; // !FAKE: dead store ends t so cse keeps q in its own register
    if (*q == 0xFF) {
    fail:
        a0[0] = 3;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        a0[0x194] = a0[0x1D];
    } else {
        a0[0] = 0x13;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        a0[0x1D] = *q;
    }
}
