/* Shared body (DK-5), from the banked draft of func_800F33B0_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

void DEDUP_NAME(u8* o) {
    u8* q0;
    u8* q1;
    u8* q2;
    u8* q3;
    s32 v;
    s32 t;
    s32 e;
    s32 a;

    if (o[0x15] != 0) {
        q0 = g_Player;
        if (((*(s16*)(q0 + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(q0 + 0xA))
                 : (*(s16*)(q0 + 0xA) - *(s16*)(o + 0xA))) >= 0x48) {
            q1 = g_Player;
            a = *(s16*)(q1 + 0xA);
            t = *(s16*)(o + 0xA) + 0x24;
            e = a - t;
            if (e >= 0) {
                v = ((e << 16) / 50);
            } else {
                v = (((t - a) << 16) / 50);
            }
            *(s32*)(o + 0x20) = v;
        } else {
            *(s32*)(o + 0x20) = 0x170A3;
        }
    } else {
        q2 = g_Player;
        if (((*(s16*)(q2 + 0xA) - *(s16*)(o + 0xA)) < 0
                 ? (*(s16*)(o + 0xA) - *(s16*)(q2 + 0xA))
                 : (*(s16*)(q2 + 0xA) - *(s16*)(o + 0xA))) >= 0x48) {
            q3 = g_Player;
            a = *(s16*)(q3 + 0xA);
            t = *(s16*)(o + 0xA) - 0x24;
            e = a - t;
            if (e >= 0) {
                v = -((e << 16) / 50);
            } else {
                v = -(((t - a) << 16) / 50);
            }
            *(s32*)(o + 0x20) = v;
        } else {
            *(s32*)(o + 0x20) = -0x170A3;
        }
    }
    *(s32*)(o + 0x24) = 0x30000;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0x2000;
    o[0x67] = 0;
    o[6]++;
}
