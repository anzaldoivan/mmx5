/* Shared body (DK-5), from the banked draft of func_800F851C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800F7FF4_ovl07(u8*, s16, s16);
extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern s32 func_8003240C(u8* a0);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* o) {
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 v;
    s32 d;
    s16 x;
    u8* p;
    s32 k;

    x = *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80));
    r1 = func_800F7FF4_ovl07(
        o, x - 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r2 = func_800F7FF4_ovl07(
        o, x + 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    r3 = func_800F7FF4_ovl07(
        o, *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)),
        *(u16*)(o + 0xE) + 0x10);
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r4 = func_800F7FF4_ovl07(o, x - 1, *(u16*)(o + 0xE) + 0x10);
    r5 = func_800F7FF4_ovl07(
        o, *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)),
        *(s16*)(o + 0xE));
    x = (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82);
    r6 = func_800F7FF4_ovl07(o, x - 1, *(s16*)(o + 0xE));
    v = *(s32*)(o + 0x20);
    if ((v > 0 && (r3 != 0 || (*(u8*)(o + 0x70) & 1))) ||
        (v < 0 && (r4 != 0 || (*(u8*)(o + 0x70) & 2))) ||
        (v > 0 && (r5 != 0 || (*(u8*)(o + 0x70) & 1))) ||
        (v < 0 && (r6 != 0 || (*(u8*)(o + 0x70) & 2)))) {
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(u8*)(o + 0x6) = 2;
        *(u16*)(o + 0xA) = (*(u16*)(o + 0xA) & 0xFFF0) | 8;
        return;
    }
    func_8002DED4(o);
    func_8002FB58(o);
    if (r1 == 0 && r2 == 0 && !(*(u8*)(o + 0x70) & 8)) {
        k = 0x1000;
        v = *(u16*)(o + 0xA);
        *(s32*)(o + 0x2C) = k;
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        k = 1;
        *(u8*)(o + 0x6) = k;
        *(u8*)(o + 0x85) = 0;
        v &= 0xFFF0;
        v |= 8;
        *(u16*)(o + 0xA) = v;
        return;
    }
    d = *(s16*)(o + 0x7C) - *(s16*)(o + 0xA);
    if (!(d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(o + 0x7C) < 0x30)) {
        if (*(s32*)(o + 0x20) > 0) {
            *(u16*)(o + 0xA) = *(u16*)(o + 0x7C) + 0x30;
        } else {
            *(u16*)(o + 0xA) = *(u16*)(o + 0x7C) - 0x30;
        }
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(u8*)(o + 0x6) = 2;
    }
    p = D_8009A0A0;
    if (p[0xF8] == 0) {
        d = *(s16*)(p + 0xA) - *(s16*)(o + 0xA);
        if (d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(p + 0xA) < 0x30) {
            func_8003240C(o);
        }
    }
}
