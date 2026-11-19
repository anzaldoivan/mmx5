/* Shared body (DK-5), from the banked draft of func_800F64F8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern s32 D_80101C9C_ovl04[];
extern s32 D_80101CBC_ovl04[];

void DEDUP_NAME(u8 n, u8* arg1, u8* src, s8 arg3) {
    u8* p;

    while (n != 0) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1A;
            p[0x15] = random_byte() & 0x40;
            p[2] = arg3;
            *(s32*)(p + 8) =
                *(s32*)(src + 8) + D_80101C9C_ovl04[random_byte() & 7];
            *(s32*)(p + 0xC) =
                *(s32*)(src + 0xC) + D_80101CBC_ovl04[random_byte() & 7];
            p[0x54] = arg1[n];
            *(s32*)(p + 0x30) = *(s32*)(src + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(src + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(src + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(src + 0x42);
            p[0x14] = g_Player[0x14];
        }
        n--;
    }
}
