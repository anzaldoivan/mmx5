/* Shared body (DK-5), from the banked draft of func_80028A20 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80027AA8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

void func_80028DFC(s32, s32, s32, s32, s32);

void DEDUP_NAME(s32 arg0, s16 arg1, s16 arg2, u16* arg3) {
    s32 var_v1;
    s32 var_s4;
    s32 var_s3;
    // !FAKE: pins var_s2 to $18; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 var_s2 asm("$18");
    s32 var_s1;
    s32 var_s0;
    s32 sp18;

    var_s4 = arg2;
    var_v1 = 0;
    var_s3 = ((s16*)arg3)[1];
    sp18 = arg1;
    if (arg3[3] != 0) {
        do {
            var_s0 = ((s16*)arg3)[0];
            var_s2 = sp18;
            var_s1 = 0;
            if (arg3[2] != 0) {
                do {
                    func_80028DFC(arg0, var_s2, var_s4, var_s0, var_s3);
                    var_s1 += 1;
                    var_s2 += 0x10;
                    var_s0 += 0x10;
                } while (var_s1 < arg3[2]);
            }
            var_v1 += 1;
            var_s4 += 0x10;
            var_s3 += 0x10;
        } while (var_v1 < arg3[3]);
    }
}
