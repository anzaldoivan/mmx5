#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80101D9C_ovl07[];
extern u8 D_80101D90_ovl07[];
extern u8 D_800767E0[];

void func_800FCCAC_ovl07(u8* obj) {
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
        set_animation(obj, 6);
    } else {
        set_animation(obj, 5);
    }
    if (D_800D1C0C.s != 12) {
        *(s16*)(obj + 0x82) = 0;
        *(s16*)(obj + 0x84) = 0;
    } else {
        *(s16*)(obj + 0x82) = -0x1B60;
        *(s16*)(obj + 0x84) = -0x440;
    }
    c = 1;
    obj[3] = c;
}

extern s32 func_80032F70(u8* a0);
extern s32 func_8003240C(u8* a0);
extern s32 func_800326BC(u8* a0);

extern u8 D_8009A244;
extern u8 D_8009A198;
extern s16 D_80101D3C_ovl07[][2];
extern s16 D_80101D18_ovl07[][2];
extern u8 D_80101D70_ovl07[];
extern u8 D_80101D88_ovl07[];
extern u8 D_80101D60_ovl07[];
extern u8 D_80101D78_ovl07[];
extern u8 D_80101D68_ovl07[];
extern u8 D_80101D80_ovl07[];
extern u8 D_80101D9C_ovl07[];
extern u8 D_80101D90_ovl07[];
extern u8 D_80101DA0_ovl07[];
extern u8 D_80101D94_ovl07[];
extern u8 D_80101D98_ovl07[];

void func_800FCDD0_ovl07(u8* o) {
    u8* p = *(u8**)(o + 0x7C);

    if (p[0x8E] != 0) {
        p[0x8E] = 2;
        if (D_800D1C0C.s != 12) {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D70_ovl07);
        } else {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D88_ovl07);
        }
        D_8009A244 = 1;
        o[4] = 2;
        return;
    }
    if (((s8*)o)[6] == 0) {
        *(u8**)(o + 0x68) = D_80101D9C_ovl07;
        *(u8**)(o + 0x54) = D_80101D90_ovl07;
        o[0x66] = 1;
        func_80032F70(o);
        if (D_8009A198 == 0) {
            func_8003240C(o);
        }
        func_800326BC(o);
        if (D_800D1C0C.s != 12) {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D18_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D18_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D60_ovl07);
        } else {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D18_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D18_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D78_ovl07);
        }
        D_8009A244 = 1;
        *(s16*)(o + 0x80) = 6;
        o[6]++;
    } else if (((s8*)o)[6] == 1) {
        if (--*(s16*)(o + 0x80) == -1) {
            *(u8**)(o + 0x68) = D_80101DA0_ovl07;
            *(u8**)(o + 0x54) = D_80101D94_ovl07;
            ((volatile u8*)
                 o)[6]++; // !FAKE: volatile stops the dispatch hoisting the lbu
        }
    } else if (((s8*)o)[6] == 2) {
        func_80032F70(o);
        if (D_8009A198 == 0) {
            func_8003240C(o);
        }
        if (((s8*)o)[2] & 0x80) {
            o[0x60] = 4;
            *(u8**)(o + 0x50) = D_80101D98_ovl07;
        }
        func_800326BC(o);
        o[0x66] = 0;
        if (D_800D1C0C.s != 12) {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D68_ovl07);
        } else {
            func_80028B18(
                ((s8*)o)[0x14],
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][0] + *(u16*)(o + 0x82)),
                (s16)(D_80101D3C_ovl07[o[2] & 0x1F][1] + *(u16*)(o + 0x84)),
                D_80101D80_ovl07);
        }
        D_8009A244 = 1;
        o[6]++;
    } else if (((s8*)o)[6] == 3) {
        if (((s8*)o)[2] & 0x80) {
            func_800317B8(o);
        }
    }
    animate_object(o);
}
