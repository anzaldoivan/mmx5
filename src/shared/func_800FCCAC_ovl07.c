/* Shared body (DK-5), from the banked draft of func_800FCCAC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80101D9C_ovl07[];
extern u8 D_80101D90_ovl07[];
extern u8 D_800767E0[];
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    s32 c;
    u8 t;
    s32 v;

    obj[4] = 1;
    obj[5] = 2;
    obj[6] = 0;
    obj[0] = 0x41;
    t = g_Player[0x14];
    c = 6;
    obj[0x16] = c;
    *(u8**)(obj + 0x68) = D_80101D9C_ovl07;
    *(u8**)(obj + 0x54) = D_80101D90_ovl07;
    v = *(s32*)(obj + 8);
    obj[0x47] = 0;
    obj[0x5C] = 0;
    obj[0x61] = 0;
    *(s32*)(obj + 0x50) = 0;
    obj[0x65] = 0;
    *(u8**)(obj + 0x58) = D_800767E0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x75] = 1;
    obj[0x76] = 0;
    obj[0x60] = 0;
    obj[0x14] = t;
    if (*(s32*)(g_Player + 8) < v) {
        *(s32*)(obj + 0x20) = 0;
    }
    if (((signed char*)obj)[2] & 0x80) {
        DEDUP_CALLEE(obj, 6);
    } else {
        DEDUP_CALLEE(obj, 5);
    }
    if (D_800D1C0C != 12) {
        *(s16*)(obj + 0x82) = 0;
        *(s16*)(obj + 0x84) = 0;
    } else {
        *(s16*)(obj + 0x82) = -0x1B60;
        *(s16*)(obj + 0x84) = -0x440;
    }
    c = 1;
    obj[3] = c;
}
