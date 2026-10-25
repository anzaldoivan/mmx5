/* Shared body (DK-5), from the banked draft of func_800EEE3C_ovl24 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EA11C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u16 D_800C9320;
extern s8 D_800D1C28;
extern u16 D_800F4E60_ovl24;
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;
extern s16 D_800F5F78_ovl24;

void DEDUP_NAME(u8* self) {
    extern u8 D_800D1C00[];
    s8* e;
    s32 t;

    if (D_800C9320 & 0x8FF) {
        D_800D1C28 = D_800F5F78_ovl24;
        self[2]++;
        return;
    }
    t = D_800F5F74_ovl24 - 1;
    D_800F5F74_ovl24 = t;
    if ((t << 16) == 0) {
        e = (s8*)D_800D1C00;
        if (++e[0x28] >= D_800F5F78_ovl24) {
            self[2]++;
            e[0x28] = D_800F5F78_ovl24;
            return;
        }
        {
            // !FAKE: pins tbl to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
            register u16* tbl asm("$3") = &D_800F4E60_ovl24;
            // !FAKE: pins v to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 v asm("$5");
            s32 i = (u16)D_800F5F76_ovl24;
            i++;
            D_800F5F76_ovl24 = i;
            v = tbl[(s16)i];
            D_800F5F74_ovl24 = v;
        }
    }
}
