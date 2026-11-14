#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8004FD24(u8* a0);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8001296C(s32);
extern void func_8003D29C(s32, s32);
extern u8* func_8002D144(void);
extern s32 func_800F033C_ovl04(void);
extern s32 func_8002DF78(void);
extern u8 D_80074EE0[];
extern u8 D_80102A9C_ovl04[];
extern u8 D_800D1C00[];
extern u8 D_80102AA0_ovl04[];
extern u8 D_800755C0[];
extern u8 D_8009A0B5;
extern s8 D_8009A23C[];
extern u8* D_8010308C_ovl04;
extern u8 D_8009A1F8[];
extern u8 D_80102B50_ovl04[][2];

void func_800FC144_ovl04(u8* o) {
    s32 r;
    s32 flag;
    s32 x;
    s32 z;
    s32 v;
    s32 sum;
    s32 w;
    s32 h;
    u8* p;
    u8* g;
    u8* q;
    s32 i;

    if (o[0x8F] != 0) {
        *(u8**)(o + 0x58) = D_80074EE0;
        *(u8**)(o + 0x54) = D_80102A9C_ovl04;
        if (func_80031DD0(o)) {
            D_800D1C00[0x27] |= 1;
        }
        *(u8**)(o + 0x54) = D_80102AA0_ovl04;
        if (func_80031DD0(o)) {
            D_800D1C00[0x27] |= 1;
        }
        if (o[0x8F]-- & 2) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (o[0x8F] == 0) {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    } else {
        flag = 0;
        *(u8**)(o + 0x58) = D_800755C0;
        if (!(D_800D1C00[0x2A] & 1)) {
            *(u8**)(o + 0x54) = D_80102A9C_ovl04;
            o[0x5C] = o[0x90];
            r = func_80031DD0(o);
            if (r < 0) {
                flag = 1;
                D_800D1C00[0x2A] |= 1;
                D_800D1C00[0x27] |= 1;
                o[0x90] = 0;
                func_8004FD24(o);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
            }
            if (r > 0) {
                flag |= 1;
                D_800D1C00[0x27] |= 1;
                if (r != 0x7F) {
                    if (r == 0x19 || r == 0x1A) {
                        o[0x8F] = 2;
                    } else {
                        o[0x8F] = 0x1E;
                    }
                }
                o[0x90] = o[0x5C];
            }
        }
        if (!(D_800D1C00[0x2A] & 2)) {
            if (((s8*)D_800D1C00)[0x27] != 0) {
                *(u8**)(o + 0x58) = D_80074EE0;
            }
            *(u8**)(o + 0x54) = D_80102AA0_ovl04;
            o[0x5C] = o[0x91];
            r = func_80031DD0(o);
            if (r < 0) {
                flag |= 1;
                D_800D1C00[0x2A] |= 2;
                D_800D1C00[0x27] |= 1;
                x = *(s32*)(o + 0x8);
                z = *(s32*)(o + 0xC);
                o[0x91] = 0;
                *(s16*)(o + 0xA) += 0x20;
                *(s16*)(o + 0xE) += 0x30;
                func_8004FD24(o);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                func_8004FD90(o, 1, 0x3F, 0x3F);
                *(s32*)(o + 0x8) = x;
                *(s32*)(o + 0xC) = z;
            }
            if (r > 0) {
                flag |= 1;
                D_800D1C00[0x27] |= 1;
                if (r != 0x7F) {
                    if (r == 0x19 || r == 0x1A) {
                        o[0x8F] = 2;
                    } else {
                        o[0x8F] = 0x1E;
                    }
                }
                o[0x91] = o[0x5C];
            }
        }
        if (flag) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    }
    sum = o[0x90] + o[0x91];
    o[0x5C] = sum;
    if ((s8)sum == -0x80) {
        o[0x5C] = 0x7F;
    }
    if ((D_800D1C00[0x2A] & 3) == 3) {
        func_8001296C(10);
        D_800D1C00[0x2A] |= 4;
        func_8003D29C(0x14, D_8009A0B5);
        h = *(u16*)(o + 0x42);
        o[5] += 1;
        h &= 0x7FFF;
        *(u16*)(o + 0x42) = h;
        D_800D1C00[0x24] = 0;
        D_8009A23C[0] = 1;
        *(s16*)(o + 0x7C) = 0;
        p = func_8002D144();
        D_8010308C_ovl04 = p;
        if (p != 0) {
            p[0] = 1;
            D_8010308C_ovl04[1] = 0xB;
        }
        return;
    }
    if (func_800F033C_ovl04()) {
        v = *(s32*)(o + 0x84) + 0x10000;
        *(s32*)(o + 0x84) = v;
        if (v > 0x1FFFFF) {
            *(s32*)(o + 0x84) = 0x200000;
        }
    }
    g = D_800D1C00;
    if (((s8*)g)[0x27] != 0) {
        g[0x27] = 0;
    }
    if (*(u16*)(g + 0x28) == 0) {
        if (o[0x8D] == 0 || --o[0x8D] == 0) {
            i = func_8002DF78() & 0xF;
            g[0x28] = D_80102B50_ovl04[i][0];
            g[0x29] = D_80102B50_ovl04[i][1];
            o[0x8D] = 0x3C;
        }
    }
    q = D_8009A1F8;
    w = *(s16*)(o + 0x86) - 0x120;
    *(s16*)(o + 0xA) = *(u16*)(q + 0xA) - w;
    *(s16*)(o + 0xE) = *(u16*)(q + 0xE) + 0x58;
}
