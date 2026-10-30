/* Shared body (DK-5), from the banked draft of func_800F4390_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D210();
extern void func_80017248(u8* obj);
extern signed char D_800D1C0C;
extern u8 D_801017F0_ovl04[];

void DEDUP_NAME(u8* a0) {
    u8* o;
    u8* o2;
    u8* o3;
    s32 y;
    u8 idx;
    u8* tbl;

    y = 0x410;
    if (D_800D1C0C != 12) {
        y = 0x1520;
    }
    o = func_8002D210();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 7;
        *(u16*)(o + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
        *(u16*)(o + 0x40) = *(u16*)(a0 + 0x40);
        *(s32*)(o + 0x30) = *(s32*)(a0 + 0x30);
        *(s32*)(o + 0x3C) = *(s32*)(a0 + 0x3C);
        *(u8**)(o + 0x7C) = a0;
        if (a0[0x8F] == 0) {
            *(u16*)(a0 + 0x7C) = 0x243;
            *(u16*)(a0 + 0x7E) = 0;
            *(s32*)(o + 8) = *(s32*)(a0 + 8) - 0x300000;
            o[0x82] = a0[0x91];
            *(u16*)(o + 0x80) = *(u16*)(a0 + 0xA) - 0x30;
            o[2] = 0x11;
        } else {
            *(u16*)(a0 + 0x7C) = 0x460;
            a0[0x8D] = 0;
            a0[0x8E] = 0;
            *(u16*)(a0 + 0x94) = *(u16*)(a0 + 0xE);
            *(u16*)(o + 0xA) = y;
            idx = a0[0x91];
            *(u16*)(o + 0x80) = y;
            tbl = &D_801017F0_ovl04[idx];
            o[0x82] = idx;
            o[2] = *tbl;
            if (idx == 6 || idx == 7) {
                o2 = func_8002D210();
                if (o2 != 0) {
                    o2[0] = 0x41;
                    o2[1] = 7;
                    *(u16*)(o2 + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(o2 + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(o2 + 0x3C) = *(s32*)(a0 + 0x3C);
                    *(u16*)(o2 + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                    *(u16*)(o2 + 0xA) = y;
                    *(u8**)(o2 + 0x7C) = a0;
                    o2[0x82] = idx;
                    o2[2] = *tbl - 1;
                    *(u16*)(o2 + 0x80) = y;
                }
                o3 = func_8002D210();
                if (o3 != 0) {
                    o3[0] = 0x41;
                    o3[1] = 7;
                    *(u16*)(o3 + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(o3 + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(o3 + 0x3C) = *(s32*)(a0 + 0x3C);
                    *(u16*)(o3 + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
                    *(u16*)(o3 + 0xA) = y;
                    *(u8**)(o3 + 0x7C) = a0;
                    o3[0x82] = idx;
                    o3[2] = *tbl - 2;
                    *(u16*)(o3 + 0x80) = y;
                }
            }
        }
    }
    a0[6] = 1;
    func_80017248(a0);
}
