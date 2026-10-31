/* Shared body (DK-5), from the banked draft of func_800F88F0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800F7FF4_ovl07(u8*, s16, s16);
extern s32 func_80016490(s32, s32, void*);
extern s32 func_8002A5C4(s32, s32, s32);
extern void func_8002DED4(u8* obj);
extern s32 func_8003240C(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* o) {
    s32 r1;
    s32 r2;
    u8* p;
    s32 d;
    s16 x;

    x = *(u8*)(o + 0x82) + (*(u16*)(o + 0xA) + *(s8*)(o + 0x80));
    r1 = func_800F7FF4_ovl07(
        o, x - 1, *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    r2 = func_800F7FF4_ovl07(
        o, (*(u16*)(o + 0xA) + *(s8*)(o + 0x80)) - *(u8*)(o + 0x82),
        *(u8*)(o + 0x83) + (*(u16*)(o + 0xE) + *(s8*)(o + 0x81)));
    if ((*(u8*)(o + 0x70) & 8) || r1 != 0 || r2 != 0) {
        *(s16*)(o + 0xC) = 0;
        *(u16*)(o + 0xE) = (*(u16*)(o + 0xE) & 0xFFF0) | 8;
        func_80016490(5, 0x26, 0);
        if (*(u8*)(o + 0x85) >= 0x11) {
            func_8002A5C4(0x10, 2, 1);
        }
        *(s16*)(o + 0x8) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(u8*)(o + 0x6) = 2;
    }
    if (*(s32*)(o + 0x24) <= -0x20000) {
        *(s32*)(o + 0x24) = -0x20000;
    }
    func_8002DED4(o);
    p = D_8009A0A0;
    *(u8*)(o + 0x85) += 1;
    if (p[0xF8] == 0) {
        d = *(s16*)(p + 0xA) - *(s16*)(o + 0xA);
        if (d >= 0 ? d < 0x30 : *(s16*)(o + 0xA) - *(s16*)(p + 0xA) < 0x30) {
            func_8003240C(o);
        }
    }
    func_8002FB58(o);
}
