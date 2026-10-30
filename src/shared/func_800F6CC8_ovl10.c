/* Shared body (DK-5), from the banked draft of func_800F6CC8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern void func_8002D6FC(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800FBF3C_ovl10[];
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* o) {
    s32 lim;
    s32 mid;
    s32 v;
    s32 y;
    u8 f;

    *(u8**)(o + 0x54) = D_800FBF3C_ovl10;
    if (D_800D1C0C != 12) {
        lim = 0x3F0;
        mid = 0x2000;
    } else {
        lim = 0x30;
        mid = 0xB00;
    }
    if (*(s16*)(o + 0x88) != 0) {
        (*(s16*)(o + 0x88))--;
        return;
    }
    *(u16*)(o + 0x42) &= 0x7FFF;
    func_800317B8(o);
    func_80017248(o);
    if (func_80031DD0(o) < 0) {
        o[4] = 0xD;
        func_8004FD24(o);
        return;
    }
    func_8002DED4(o);
    y = *(s16*)(o + 0xE);
    y = lim < y;
    if (y != 0) {
        func_8002FB58(o);
    }
    y = *(s16*)(o + 0xA);
    if (y > mid + 5 && (v = *(s32*)(o + 0x28)) < 0) {
        *(s32*)(o + 0x28) = -v;
    } else if (y < mid - 5 && (v = *(s32*)(o + 0x28)) > 0) {
        *(s32*)(o + 0x28) = -v;
    }
    f = o[0x70];
    if (f & 2) {
        *(s32*)(o + 0x28) = -0x17D0;
        *(s32*)(o + 0x24) = -0x20000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x2C) = -0x770;
        (*(s16*)(o + 0xA))++;
    } else if (f & 1) {
        *(s32*)(o + 0x28) = 0x17D0;
        *(s32*)(o + 0x24) = -0x20000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x2C) = -0x770;
        (*(s16*)(o + 0xA))--;
    }
    if (o[0x70] & 8) {
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        if (*(s16*)(o + 0x92) == 0) {
            func_8002D6FC(o);
            return;
        }
        if (!(--(*(s16*)(o + 0x92)) & 1)) {
            o[3] = 0;
            return;
        }
    }
    if ((*(s8**)(o + 0x7C))[4] == 2) {
        o[3] = 0;
        func_8002D6FC(o);
        return;
    }
    if (func_8002D938(o, 0x60, 0x60) == 1) {
        o[4] = 0xD;
        return;
    }
    func_8002D9EC(o, 0x20, 0x20);
}
