/* Shared body (DK-5), from the banked draft of func_800F8AD0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

extern s32 func_8003240C(u8* a0);

void DEDUP_NAME(u8* o) {
    u8* g;
    // !FAKE: register pin keeps the second result in v0
    register s32 r2 asm("$2");
    s32 r1;
    s16 x;

    func_8002FB58(o);
    x = *(s16*)(o + 0xA) + (s8)o[0x80] + o[0x82];
    r1 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, x - 1, *(s16*)(o + 0xE) + (s8)o[0x81] + o[0x83]);
    r2 = ((s32(*)(u8*, s16, s16))func_800F7FF4_ovl07)(
        o, *(s16*)(o + 0xA) + (s8)o[0x80] - o[0x82],
        *(s16*)(o + 0xE) + (s8)o[0x81] + o[0x83]);
    g = g_Player;
    if (!(o[0x70] & 8) && r1 == 0 && r2 == 0) {
        *(s32*)(o + 0x2C) = 0x1000;
        o[6] = 1;
        o[0x85] = 0;
    } else {
        o[0x84] = g[0x71];
        if (g_Player[0xF8] == 0) {
            if (((*(s16*)(g_Player + 0xA) - *(s16*)(o + 0xA)) < 0
                     ? (*(s16*)(o + 0xA) - *(s16*)(g_Player + 0xA))
                     : (*(s16*)(g_Player + 0xA) - *(s16*)(o + 0xA))) < 0x30) {
                func_8003240C(o);
            }
        }
        o[0x84] ^= g[0x71];
        if ((*(s32*)(g + 4) & 0xFFFF00) == 0x10C00 && g[0xFA] == 3) {
            if ((o[0x84] & 2) && g[0x15] == 0) {
                *(s32*)(o + 0x20) = -0x40000;
                *(s32*)(o + 0x28) = -0x2400;
            } else {
                if (!(o[0x84] & 1) || g[0x15] != 0x40) {
                    return;
                }
                *(s32*)(o + 0x20) = 0x40000;
                *(s32*)(o + 0x28) = 0x2400;
            }
            *(s32*)(o + 0x24) = 0;
            *(s32*)(o + 0x2C) = 0;
            o[6] = 0;
            *(s16*)(o + 0x7C) = *(s16*)(o + 0xA);
        }
    }
}
