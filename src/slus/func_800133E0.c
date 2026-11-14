/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/8001344C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @4e16dfc src/main/2824.c:func_800128EC, AGPL-3.0; proven shared with X6 by exact signature ea1f214c77bc (see THIRD_PARTY.md). */
#include "types.h"

void func_800133E0(s32* arg0, s32* arg1, s32 arg2) {
    do {
        s32 a = arg0[0];
        s32 b = arg0[1];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 c asm("$8") = arg0[2];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 d asm("$9") = arg0[3];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 e asm("$10") = arg0[4];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 f asm("$11") = arg0[5];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 g asm("$12") = arg0[6];
        // !FAKE: register pin, retail copy temps in v0/v1/t0-t5
        register s32 h asm("$13") = arg0[7];
        do {
            arg1[0] = a;
            arg1[1] = b;
            arg1[2] = c;
            arg1[3] = d;
            arg1[4] = e;
            arg1[5] = f;
            arg1[6] = g;
            arg1[7] = h;
        } while (
            0); // !FAKE: fence keeps the eight loads above the stores (C0294)
        arg2--;
        arg0 += 8;
        arg1 += 8;
    } while (arg2 != 0);
}
